#include "paddle.h"
#include <raylib.h>

Paddle::Paddle()
{
  width = 10;
  height = 120;
  speedY = 5;
  score = 0;
}
int Paddle::getwidth()
{
  return width;
}
int Paddle::getheight()
{
  return height;
}
int Paddle::getX()
{
  return x;
}
int Paddle::getY()
{
  return y;
}
void Paddle::setxy(int a, int b, int screenWidth, int screenHeight)
{
  x = a;
  y = b;
}

void Paddle::Update()
{
  const int screenHeight = GetScreenHeight();

  // Move up
  if (IsKeyDown(KEY_UP))
  {
    if (y > 0)
      y -= speedY;
  }

  // Move down
  if (IsKeyDown(KEY_DOWN))
  {
    if (y + height < screenHeight)
      y += speedY;
  }
}

void Paddle::Draw() const
{
  DrawRectangle(x, y, width, height, WHITE);
}
