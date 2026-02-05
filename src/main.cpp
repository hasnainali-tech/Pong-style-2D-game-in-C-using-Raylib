#include <raylib.h>
#include "ball.h"
#include "paddle.h"

int main()
{
    const Color darkGreen = {20, 160, 133, 255};
    bool gameOver = false;
    int winner = 0;
    constexpr int screenWidth = 1000;
    constexpr int screenHeight = 600;
    Rectangle restartButton = {
        screenWidth / 2 - 120,
        screenHeight / 2 + 60,
        240,
        60};

    Ball ball;
    Paddle player;
    int width = player.getwidth();
    int height = player.getheight();
    player.setxy(screenWidth - width - 10, screenHeight / 2 - height / 2, screenWidth, screenHeight);

    comp computer;
    computer.setxy(width + 10, screenHeight / 2 - height / 2, screenWidth, screenHeight);

    InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        if (!gameOver)
        {
            ball.Update();
            player.Update();
            computer.update(ball.y, ball.x);

            // Player paddle collision
            if (CheckCollisionCircleRec(
                    Vector2{(float)ball.x, (float)ball.y},
                    (float)ball.getradius(),
                    Rectangle{
                        (float)player.getX(),
                        (float)player.getY(),
                        (float)player.getwidth(),
                        (float)player.getheight()}))
            {
                ball.speedX *= -1;
            }

            // Computer paddle collision
            if (CheckCollisionCircleRec(
                    Vector2{(float)ball.x, (float)ball.y},
                    (float)ball.getradius(),
                    Rectangle{
                        (float)computer.getX(),
                        (float)computer.getY(),
                        (float)computer.getwidth(),
                        (float)computer.getheight()}))
            {
                ball.speedX *= -1;
            }

            int goal = ball.checkGoal();

            if (goal == 2)
            {
                computer.score++;
                ball.reset();
            }
            else if (goal == 1)
            {
                player.score++;
                ball.reset();
            }

            if (computer.score == 5)
            {
                gameOver = true;
                winner = 1;
            }
            else if (player.score == 5)
            {
                gameOver = true;
                winner = 2;
            }

            BeginDrawing();
            ClearBackground(darkGreen);
            ball.Draw();
            player.Draw();
            computer.Draw();
            DrawText(TextFormat("%i", computer.score), screenWidth / 4 - 20, 20, 80, WHITE);
            DrawText(TextFormat("%i", player.score), (screenWidth * 0.75) - 20, 20, 80, WHITE);
            EndDrawing();
        }
        else
        {
            Vector2 mouse = GetMousePosition();
            bool hover = CheckCollisionPointRec(mouse, restartButton);

            if (hover && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                gameOver = false;
                winner = 0;
                player.score = 0;
                computer.score = 0;

                ball.reset();
            }
            BeginDrawing();
            ClearBackground(darkGreen);

            if (winner == 1)
            {
                const char *text = "Computer Won The Game";
                DrawText(
                    text,
                    screenWidth / 2 - MeasureText(text, 50) / 2 - 20,
                    screenHeight / 2 - 25,
                    50,
                    WHITE);
            }
            else
            {
                const char *text = "You Won The Game";
                DrawText(
                    text,
                    screenWidth / 2 - MeasureText(text, 50) / 2 - 20,
                    screenHeight / 2 - 25,
                    50,
                    WHITE);
            }

            Color btnColor = hover ? GRAY : WHITE;
            DrawRectangleRec(restartButton, btnColor);
            DrawRectangleLinesEx(restartButton, 2, BLACK);

            const char *btnText = "RESTART";

            DrawText(btnText,
                     restartButton.x + (restartButton.width / 2) - MeasureText(btnText, 30) / 2,
                     restartButton.y + restartButton.height / 2 - 15,
                     30,
                     BLACK);

            EndDrawing();
        }
    }

    CloseWindow();
}