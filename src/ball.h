#pragma once

class Ball
{
public:
    Ball();
    void Update();
    void Draw() const;
    int BallY();
    int x;
    int y;
    int speedX;
    int speedY;
    int getradius();
    void reset();
    int checkGoal();

private:
    int radius;
};