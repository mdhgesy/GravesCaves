#include <inputs.h>

Vector2 GetPlayerInputDirection()
{
  Vector2 direction = {0.0f, 0.0f};

  // opposite movement cancels out
  // A(1) - D(1) = 0

  direction.y = IsKeyDown(KEY_D) - IsKeyDown(KEY_A);
  direction.x = IsKeyDown(KEY_W) - IsKeyDown(KEY_S);

  return Vector2Normalize(direction);
}

Vector3 GetPlayerMouseInput()
{
  Vector3 mouse_movement = {0};
  mouse_movement.x = GetMouseDelta().x * 0.1f;
  mouse_movement.y = GetMouseDelta().y * 0.1f;

  return mouse_movement;
}