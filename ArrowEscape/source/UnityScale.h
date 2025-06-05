#pragma once
#include "EnterValue.h"
#include "Vector2.h"

class UnityScale
{
public:
	static Vector2f ParseToUnityScale(Vector2 vector2);
	static Vector2 ParseToPixel(Vector2f vector2f);

private:
	static const float scalingMagnificationFromPixel;
	static const Vector2 windowSize;
	static const Vector2f windowSize_UnityScale;
};