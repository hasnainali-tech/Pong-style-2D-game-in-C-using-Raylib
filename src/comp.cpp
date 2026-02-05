#include "paddle.h"
#include <raylib.h>

void comp::update(int ball_y, int ball_x)
{
  // Simple AI: follow the ball
  if (ball_x > GetScreenWidth())
  {
    if (y > GetScreenWidth() / 2)
    {
      int b = y - GetScreenWidth() / 2;
      y = y - b;
    }
    else if (y < GetScreenWidth() / 2)
    {
      int b = GetScreenWidth() / 2 - y;
      y = y + b;
    }
  }
  if (ball_y > y + getheight() / 2 && ball_x <= GetScreenWidth())
    y += GetRandomValue(2, 4);
  else if (ball_y < y + getheight() / 2 && ball_x <= GetScreenWidth())
    y -= GetRandomValue(5, 4);
}