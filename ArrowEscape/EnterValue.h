#pragma once
#include "Vector2.h"

class EnterValue
{
public:
	static constexpr int WindowWidth = 640;
	static constexpr int WindowHeight = 640;
	static constexpr int CoordinateWidth = 1531;
	static constexpr int CoordinateHeight = 1531;
	static constexpr float WindowWidth_UnityScale = 15.0f;

	static constexpr int GameFPS = 30;

	static constexpr int LimitNumOfGameObject = 1024;

	struct GameScene
	{
		struct Background
		{
			static constexpr float StageWidth = 15.0f;
			static constexpr float StageHeight = 15.0f;
			static constexpr float ImageMagnification = 3.0f;
			static constexpr Vector2 Offset = Vector2{ 768, 768 };
		};
		struct Player
		{
			static constexpr float ImageMagnification = 1.0f;
			static constexpr Vector2 Offset = Vector2{ 89, 96 };
		};
	};
};
enum class SceneStatus
{
	GameScene
};