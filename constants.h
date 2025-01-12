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
  static constexpr float brick_width{ 42.0f };
  static constexpr float brick_height{ 20.0f };
  static constexpr int brick_rows{ 5 };
  static constexpr int brick_columns{ 10 };
  static constexpr float brick_offset{ (float)(window_width - brick_columns*brick_width) / 2.0 };
};

#endif // CONSTANTS_H
