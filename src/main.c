#include <raylib.h>
#include <raymath.h>
#include <rcamera.h>

#define SCREENWIDTH 1600
#define SCREENHEIGHT 1200

int main(void)
{
  InitWindow(SCREENWIDTH, SCREENHEIGHT, "CAMERA DEMO");

  Camera Camera = {0};
  Camera.position = (Vector3){0.0f, 2.0f, 4.0f};
  Camera.target = (Vector3){0.0f, 2.0f, 0.0f};
  Camera.up = (Vector3){0.0f, 1.0f, 0.0f};
  Camera.fovy = 60.0f;
  Camera.projection = CAMERA_PERSPECTIVE;

  int camera_mode = CAMERA_FIRST_PERSON;

  DisableCursor();
  SetTargetFPS(60);

  while (!WindowShouldClose())
  {
    UpdateCamera(&Camera, camera_mode);

    BeginDrawing();
    ClearBackground(RAYWHITE);
    BeginMode3D(Camera);

    DrawPlane((Vector3){0.0f, 0.0f, 0.0f}, (Vector2){32.0f, 32.0f}, LIGHTGRAY);
    DrawCube((Vector3){-16.0f, 2.5f, 0.0f}, 1.0f, 5.0f, 32.0f, BLUE);
    DrawCube((Vector3){16.0f, 2.5f, 0.0f}, 1.0f, 5.0f, 32.0f, LIME);
    DrawCube((Vector3){0.0f, 2.5f, 16.0f}, 32.0f, 5.0f, 1.0f, GOLD);
    
    EndMode3D();
    EndDrawing();
  }

  CloseWindow();
  return 0;
}