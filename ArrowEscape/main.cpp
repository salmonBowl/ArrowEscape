/*
	main.cpp
		�Q�[�����[�v���L�q���܂�
*/

/*
	���s�̗��� :

	  main �� SceneManager �� GameScene:Scene �� Player:Sprite:GameObject
	   -�Q�[�����[�v           -DxLib�֌W + �I�u�W�F�N�g�z�u
			   -currentScene�A�N�Z�X              -�I�u�W�F�N�g���Ƃ̋���

	�N���X�݌v :

	Scene�t�B���^
	  SceneManager
	  Scene
	   - GameScene
	  GameObjectAdmin
	   - GameScene_Admin : ������GameObject�̔z�u�E�����E�폜
	  GameObject
	   - Sprite
		 - Player : �eGameObject(�摜�^�C�v)
		 - BackGround
	   - Shape
		 - Beam
	System�t�B���^
	  FPS
	  GameWindow
	  Input
	  Mathf
	  Transform
	  UnityScale
	  Vector2

	  EnterValue : �l�̓���


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

