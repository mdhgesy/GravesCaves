#include <playermovement.h>

float CalculatePlayerMovespeed(float base_speed, float speed_modifier)
{
  return base_speed * speed_modifier;
}

Vector3 CalculateCameraVector(Vector2 InputDirection, float player_speed, float delta_time)
{
  Vector3 CameraVelocity = {0};

  // multiplies normalized direction by movement speed and delta time

  CameraVelocity.x = InputDirection.x * player_speed * delta_time;
  CameraVelocity.y = InputDirection.y * player_speed * delta_time;

  return CameraVelocity;
}
