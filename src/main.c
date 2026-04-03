#include <raylib.h>
#include <raymath.h>
#include <rcamera.h>

#define WINDOW_WIDTH 1600
#define WINDOW_HEIGHT 1000
#define WINDOW_NAME "SHON"

int targetfps = 60;

int main(void)
{
  struct Vector2 wektor = {0, 0};
  int xdirection = 1;
  int ydirection = 1;
  SetTargetFPS(targetfps);

  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);

  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    wektor.x += xdirection * GetFrameTime() * 100.0f;
    wektor.y += ydirection * GetFrameTime() * 100.0f;
    if (wektor.x <= 0 || wektor.x >= WINDOW_WIDTH)
    {
      xdirection *= -1.0f;
    }
    if (wektor.y <= 0 || wektor.y >= WINDOW_HEIGHT)
    {
      ydirection *= -1.0f;
    }
    DrawCircleV(wektor, 30, MAGENTA);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}