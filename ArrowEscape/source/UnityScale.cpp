#include "UnityScale.h"
#include "GameWindow.h"
#include "Mathf.h"

#include <stdio.h> //一時的にテスト

const float UnityScale::scalingMagnificationFromPixel = EnterValue::WindowWidth_UnityScale / (float)GameWindow::CoordinateWidth;
const Vector2 UnityScale::windowSize = Vector2{ GameWindow::CoordinateWidth, GameWindow::CoordinateHeight };
const Vector2f UnityScale::windowSize_UnityScale = Vector2f{ EnterValue::WindowWidth_UnityScale, GameWindow::CoordinateHeight * UnityScale::scalingMagnificationFromPixel };

Vector2f UnityScale::ParseToUnityScale(Vector2 vector2)
{
	const float m = scalingMagnificationFromPixel;
	
	Vector2f vector2f = Vector2f{
		(float)(vector2.x - (windowSize.x / 2)) * m ,
		(float)((windowSize.y / 2) - vector2.y) * m };

	return vector2f;
}

Vector2 UnityScale::ParseToPixel(Vector2f vector2f)
{
	const float m = scalingMagnificationFromPixel;

	int x = Mathf::Round(vector2f.x / m);
	int y = Mathf::Round(vector2f.y / m);

	Vector2 vector2 = Vector2{ x + (windowSize.x / 2), (windowSize.y / 2) - y};

	return vector2;
}
