#pragma once

#include <raylib.h>
#include <raymath.h>

float CalculatePlayerMovespeed(float base_speed, float speed_modifier);

Vector3 CalculateCameraVector(Vector2 InputDirection, float player_speed, float delta_time);