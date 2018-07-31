#pragma once

#include <cstdint>
#include <vector>

class Game {
public:
  //This is default fullscreen shadow buffer. You can use it if you want to.
  static unsigned *shadow_buf;

  void init_game();

  void close_game();

  // ��������� ����.
  void draw_game();

  // ���������� ��������. dt - ����� � ����������� ������.
  void act_game(float dt);

private:
  // ����� ����.
  enum State {
    Start,
    Play,
    Over,
  };

  State state;

  // ��������� ������.
  const uint32_t black = make_color(0x00, 0x00, 0x00);
  const uint32_t gray = make_color(0xA0, 0xA0, 0xA0);
  const uint32_t red = make_color(0xFF, 0x00, 0x00);
  const uint32_t yellow = make_color(0xFF, 0xFF, 0x00);
  const uint32_t blue = make_color(0x00, 0x00, 0xFF);
  const uint32_t purple = make_color(0xFF, 0x00, 0xFF);
  const uint32_t lime = make_color(0x00, 0xFF, 0x00);
  const uint32_t white = make_color(0xFF, 0xFF, 0xFF);

  // ���� � ��� ���� (����� ������, ��� ����� ������ ������-�� ���������� ��� ������).
  const int kFieldTop = 50;
  const int kFieldBottom = 450;

  // ��������� ��������.
  const int kBrickTopPosition = kFieldTop; // ���� �������� ���� ��������.
  const int kBrickColCount = 13;
  const int kBrickRowCount = 6;
  const int kBrickSpacing = 1;  // ��������� ����� ���������.
  const int kBrickHeight = 20;

  // ��������� �������.
  const int kVausMoveSpeed = 200;
  const int kVausWidth = 50;
  const int kVausHeight = 10;
  const int kVausYPos = kFieldBottom;  // ����������, �� ������� ��������� ���� �������.

  // ��������� ����.
  const float kBallSpeed = 150;
  const int kBallDiameter = 7;

  // ��������� ������ ������ � ���������.
  const int kLivesSpacing = 10;
  const float kBlinkTime = 2;
  const float kBlinkingTime = 0.5;

  // ������ ������.
  std::vector<uint32_t> colors;

  typedef std::vector<bool> Row;
  typedef std::vector<Row> Matrix;

  // ������ ��������. True ���� ��� �� ����.
  Matrix bricks;

  // ������ ������� ����������� �� ������ ������.
  int brick_width;

  // ������� ��������� ���� � �������.
  float vaus_position;
  float ball_position_x;
  float ball_position_y;
  float ball_speed_x;
  float ball_speed_y;
  float blink_timer;

  int lives;

  inline uint32_t make_color(uint8_t r, uint8_t g, uint8_t b) {
    return static_cast<uint32_t>(r) << 16 | static_cast<uint32_t>(g) << 8 | static_cast<uint32_t>(b);
  }

  void draw_rect(int pos_x, int pos_y, int width, int height, uint32_t color);
};
