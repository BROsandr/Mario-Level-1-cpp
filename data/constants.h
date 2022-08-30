#pragma once

inline constexpr int kScreenHeight{600};
inline constexpr int kScreenWidth{600};

inline constexpr int kScreenSize[]{kScreenWidth, kScreenHeight};

inline constexpr char* kOriginalCaption{"Super Mario Bros 1-1"};

// OVERHEAD INFO STATES
inline constexpr char kMainMenu[]{"main menu"};
inline constexpr char kLoadScreen[]{"load screen"};
inline constexpr char kTimeOut[]{"time out"};
inline constexpr char kGameOver[]{"game over"};
inline constexpr char kLevel1[]{"level1"};

// GAME INFO DICTIONARY KEYS
inline constexpr char kCointTotal[]{"coint total"};
inline constexpr char kScore[]{"score"};
inline constexpr char kTopScore[]{"top score"};
inline constexpr char kLives[]{"lives"};
inline constexpr char kCurrentTime[]{"current time"};
inline constexpr char kLevelState[]{"level state"};
inline constexpr char kCameraStartX[]{"camera start x"};
inline constexpr char kMarioDead[]{"mario dead"};

inline constexpr double kSizeMultiplier{2.5};
inline constexpr double kBackgroundMultiplier{2.679};
inline constexpr int kGroundHeight = kScreenHeight - 62;

// COLORS

/* constexpr int kgray[] {100, 100, 100}; */
/* constexpr int navyblue[] {100, 100, 100}; */
/* constexpr int white[] {100, 100, 100}; */
/* constexpr int red[] {100, 100, 100}; */
/* constexpr int green[] {100, 100, 100}; */
/* constexpr int gray[] {100, 100, 100}; */
/* constexpr int gray[] {100, 100, 100}; */
/* constexpr int gray[] {100, 100, 100}; */
/* constexpr int gray[] {100, 100, 100}; */
/* constexpr int gray[] {100, 100, 100}; */
/* constexpr int gray[] {100, 100, 100}; */
/* constexpr int gray[] {100, 100, 100}; */
/* constexpr int gray[] {100, 100, 100}; */
/* constexpr int gray[] {100, 100, 100}; */
/* constexpr int gray[] {100, 100, 100}; */
