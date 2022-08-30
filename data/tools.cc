#include "tools.h"

#include <SFML/Window/Event.hpp>

#include "setup.h"
#include "components/info.h"

std::map<const char*, sf::Keyboard::Key>& keybinding() {
  static std::map<const char*, sf::Keyboard::Key> keybinding;
  return keybinding;
}

Control::Control(const char caption[]) {
  Window::instance().setTitle(caption);
}

void Control::SetupStates(std::map<const char*, State*>& _state_dict, const char _start_state[]) {
  state_dict = _state_dict;
  state_name = _start_state;
  state = state_dict.at(state_name);
}

void Control::main() {
  while (!done && Window::instance().isOpen()) {
    Window::instance().clear();

    EventLoop();
    Update();

    Window::instance().display();
  }
}

void Control::EventLoop() {
  sf::Event event;
  while (Window::instance().pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      Window::instance().close();
    } else if (event.type == sf::Event::KeyPressed) {
      keys = event.key.code;
      ToggleShowFps(keys);
    } else if (event.type == sf::Event::KeyReleased) {
      keys = event.key.code;
    }
  }
}

void Control::Update() {
  current_time = clock.getElapsedTime().asSeconds();

  if (state->quit) {
    done = true;
  } else if (state->done) {
    FlipState();
  }
    
  state->Update(keys, current_time);
}

void Control::FlipState() {
  const char* previous{state_name};
  state_name = state->next;
  std::map<const char*, int> persist = state->Cleanup();
  state = state_dict.at(state_name);
  state->Startup(current_time, persist);
  state->previous = previous;
}

std::map<const char*, int> State::Cleanup() {
  done = false;
  return persist;
}

void State::Startup(double _current_time, std::map<const char*, int> _persist) {
  persist = _persist;
  start_time = current_time;
}

void Control::ToggleShowFps(sf::Keyboard::Key key) {
  if (key == sf::Keyboard::F5) {
    show_fps = !show_fps;
    if (!show_fps)
      Window::instance().setTitle(caption);
  }
}

std::map<std::string, sf::Image>& LoadAllGfx(std::filesystem::path directory,
                                                    std::vector<const char*> accept,
                                                    sf::Color colorkey) {
  static std::map<std::string, sf::Image> graphics;
  static bool is_first_pass{true};

  if (is_first_pass)
    if (std::filesystem::is_directory(directory)) {
      for (auto pic : std::filesystem::directory_iterator(directory)) {
        std::string name{pic.path().stem().string()};
        std::string ext{pic.path().extension().string()};
        std::for_each(ext.begin(), ext.end(), [](char& c) {
          c = tolower(c);
        });
        if (std::find(accept.begin(), accept.end(), ext) != accept.end()) {
          sf::Image image;
          image.loadFromFile(pic.path().string());
          graphics[name.c_str()] = image;
        }
      }
    } else {
       throw std::filesystem::filesystem_error{"path doesn't exist", std::error_code{}};
    }

  is_first_pass = false;

  return graphics;
}

void LoadSpriteSheet(sf::Color colorkey, const char* texture_name, sf::Texture& sprite_sheet) {
  sf::Image image{gfx().at(texture_name)};
  image.createMaskFromColor(colorkey);
  sprite_sheet.loadFromImage(image);
}
