#include "ball.h"
#include <raylib.h>

Ball::Ball()
    : x(500), y(300), speedX(5), speedY(5), radius(15)
{
}

void Ball::Update()
{
    x += speedX;
    y += speedY;

    const int screenHeight = GetScreenHeight();

    if ((y + radius >= screenHeight) || (y - radius <= 0))
    {
        speedY *= -1;
    }
}

int Ball::checkGoal()
{
    if (x <= 0)
    {
        return 1;
    }
    else if (x >= GetScreenWidth())
    {
        return 2;
    }

    return 0;
}

void Ball::reset()
{
    x = 500;
    y = 300;

    speedX = 5 * GetRandomValue(-1, 1);
    speedY = 5 * GetRandomValue(-1, 1);

    if (speedX == 0)
        speedX = 5;
    if (speedY == 0)
        speedY = 5;
}

void Ball::Draw() const
{
    const Color Gray = {0, 0, 0, 255};
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();
    DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, Gray);
    DrawCircle(x, y, radius, WHITE);
}

int Ball::getradius()
{
    return radius;
}