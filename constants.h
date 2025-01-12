#ifndef CONSTANTS_H
#define CONSTANTS_H

// Code for a "breakout" game
// Based on a talk by Vittorio Romeo
// Uses the SFML graphics library

struct constants {
  static constexpr int window_width{520};
  static constexpr int window_height{450};
  static constexpr float ball_speed{ 6.0f };
  static constexpr float paddle_width{ 90.0f };
  static constexpr float paddle_height{ 9.0f };
  static constexpr float paddle_speed{ 8.0f };
};

#endif // CONSTANTS_H
