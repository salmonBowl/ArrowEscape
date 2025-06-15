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
			static constexpr float GroundLevel = -7.0f;
			static constexpr float GravityVolume = 1.9f;
		};
	};
};

enum class GameObjectType
{
	Player,
	Background,
	EnemyArrow,
	Beam
};
enum class ImageAssetID
{
	PlayerImage,
	BackgroundImage,
	ArrowImage,
	BeamImage
};

enum class SceneStatus
{
	GameScene
};