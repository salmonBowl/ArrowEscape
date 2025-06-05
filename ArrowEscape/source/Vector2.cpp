#include "Vector2.h"
#include "GameScene.h"

Vector2 AddVector2(Vector2 a, Vector2 b)
{
	Vector2 vector2 = { a.x + b.x, a.y + b.y };
	return vector2;
}
Vector2f AddVector2(Vector2f a, Vector2f b)
{
	Vector2f vector2f = { a.x + b.x, a.y + b.y };
	return vector2f;
}
