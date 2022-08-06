#pragma once

#include "tools.h"

class LoadScreen : public State {
 public:
  explicit LoadScreen();
};

class GameOver : public State {
 public:
  explicit GameOver();
};

class TimeOut : public State {
 public:
  explicit TimeOut();
};
