#include <raylib.h>
#include <raymath.h>
#include <rcamera.h>

#include <inputs.h>
#include <playermovement.h>

#define SCREENWIDTH 1600
#define SCREENHEIGHT 1200

typedef struct
{
  Vector2 MoveDirection;
  Vector3 PlayerVector;
  int Health;
} Player;

void SetupCamera(Camera *C);

int main(void)
{
  InitWindow(SCREENWIDTH, SCREENHEIGHT, "CAMERA DEMO");
  DisableCursor();
  SetTargetFPS(60);

  float delta_t = 0;

  // INPUT SHOULD BE DIVIDED INTO 3 STEPS;
  // 1. GET INPUTS
  // 2. CALCULATE SPEED / MOVEMENT
  // 3. MOVE THE PLAYER (CAMERA)

  Camera Camera = {0};

  SetupCamera(&Camera);

  while (!WindowShouldClose())
  {
    delta_t = GetFrameTime();

    Vector2 InputDirection = GetPlayerInputDirection();
    Vector3 CameraVector = CalculateCameraVector(InputDirection, 1.5f, delta_t);
    Vector3 MouseVector = GetPlayerMouseInput();
    UpdateCameraPro(&Camera, CameraVector, MouseVector, 0.0f);

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