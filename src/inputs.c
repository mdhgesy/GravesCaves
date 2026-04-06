#include <inputs.h>

void HandleMovementInput(Vector3 *CameraVector, float base_move_speed)
{
  CameraVector->x = 0;
  CameraVector->y = 0;

  if (IsKeyDown(KEY_W))
  {
    CameraVector->x = 1.5 * GetFrameTime();
  }
  if (IsKeyDown(KEY_S))
  {
    CameraVector->x = -1.5 * GetFrameTime();
  }
  if (IsKeyDown(KEY_A))
  {
    CameraVector->y = -1.5 * GetFrameTime();
  }
  if (IsKeyDown(KEY_D))
  {
    CameraVector->y = 1.5 * GetFrameTime();
  }
}