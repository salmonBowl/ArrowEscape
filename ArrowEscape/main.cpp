/*
	main.cpp
		ゲームループを記述します
*/

/*
	実行の流れ :

	  main → SceneManager → GameScene:Scene → Player:Sprite:GameObject
	   -ゲームループ           -DxLib関係 + オブジェクト配置
			   -currentSceneアクセス              -オブジェクトごとの挙動

	クラス設計 :

	Sceneフィルタ
	  SceneManager
	  Scene
	   - GameScene
	  GameObjectAdmin
	   - GameScene_Admin : ここでGameObjectの配置・生成・削除
	  GameObject
	   - Sprite
		 - Player : 各GameObject(画像タイプ)
		 - BackGround
	   - Shape
		 - Beam
	Systemフィルタ
	  FPS
	  GameWindow
	  Input
	  Mathf
	  Transform
	  UnityScale
	  Vector2

	  EnterValue : 値の入力


*/

#include "DxLib.h"

#include <memory>
#include "SceneManager.h"
#include "GameScene.h"
#include "fps.h"

#include <stdio.h>


int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	AllocConsole(); FILE* out = 0; freopen_s(&out, "CON", "w", stdout);

	SceneManager manager;

	if (manager.SwitchScene(std::make_unique<GameScene>())
		== -1) return -1;

	while (manager.CanGameLoop())
	{
		printf("GameLoop\n");
		if (manager.UpdateCurrentScene() == -1) return -1;
	}

	if (manager.TerminateScene_GameExit() == -1) return -1;

	return 0;
}

