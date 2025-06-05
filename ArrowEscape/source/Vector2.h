#pragma once

struct Vector2
{
	int x;
	int y;
};
struct Vector2f
{
	float x;
	float y;
};

Vector2 AddVector2(Vector2 a, Vector2 b);
Vector2f AddVector2(Vector2f a, Vector2f b);