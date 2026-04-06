#include <raylib.h>
#include <raymath.h>
#include <rcamera.h>

#include <inputs.h>

#define SCREENWIDTH 1600
#define SCREENHEIGHT 1200

void SetupCamera(Camera *C);

int main(void)
{
  InitWindow(SCREENWIDTH, SCREENHEIGHT, "CAMERA DEMO");

  Vector3 CameraMoveVector = {0};
  Camera Camera = {0};
  SetupCamera(&Camera);

  float base_move_speed = 1.5;

  DisableCursor();
  SetTargetFPS(60);

  while (!WindowShouldClose())
  {
    HandleMovementInput(&CameraMoveVector, base_move_speed);
    UpdateCameraPro(&Camera, CameraMoveVector, (Vector3){GetMouseDelta().x * 0.05, GetMouseDelta().y * 0.05, 0.0f}, 0.0f);

    BeginDrawing();
    ClearBackground(RAYWHITE);
    BeginMode3D(Camera);

    DrawPlane((Vector3){0.0f, 0.0f, 0.0f}, (Vector2){32.0f, 32.0f}, LIGHTGRAY);
    DrawCube((Vector3){-16.0f, 2.5f, 0.0f}, 1.0f, 5.0f, 32.0f, BLUE);
    DrawCube((Vector3){16.0f, 2.5f, 0.0f}, 1.0f, 5.0f, 32.0f, LIME);
    DrawCube((Vector3){0.0f, 2.5f, 16.0f}, 32.0f, 5.0f, 1.0f, GOLD);

    EndMode3D();

    DrawFPS(10, 10);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}

void SetupCamera(Camera *C)
{
  C->position = (Vector3){0.0f, 2.0f, 4.0f};
  C->target = (Vector3){0.0f, 2.0f, 0.0f};
  C->up = (Vector3){0.0f, 1.0f, 0.0f};
  C->fovy = 60.0f;
  C->projection = CAMERA_PERSPECTIVE;
}