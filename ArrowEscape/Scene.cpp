#include "Scene.h"
#include "DxLib.h"
#include "fps.h"
#include "GameObjectAdmin.h"
#include "GameWindow.h"
#include "SceneManager.h"

Scene::Scene()
{

}

int Scene::InitScene()
{
	ChangeWindowMode(true);
	SetGraphMode(GameWindow::CoordinateWidth, GameWindow::CoordinateHeight, 32);
	SetWindowSize(GameWindow::WindowWidth, GameWindow::WindowHeight);
	if (DxLib_Init() == -1)
	{
		printf("DxLib�̏������ŃG���[�������������ߏI�����܂�\n");
		return -1;
	}

	if (!pGameObjectAdmin)
	{
		printf("NullPtrException in Scene::InitScene()\n");
		return -1;
	}
	pGameObjectAdmin->InitAllGameObject();

	return 0;
}

int Scene::UpdateScene()
{
	printf("SceneUpdate\n");

	ClearDrawScreen();
	SetDrawScreen(DX_SCREEN_BACK);

	if (!pGameObjectAdmin)
	{
		printf("NullPtrException in Scene::Update()\n");
		return -1;
	}
	pGameObjectAdmin->UpdateAllGameObject();

	FPS::FPSWait();

	ScreenFlip();

	return 0;
}
int Scene::TerminateScene()
{
	printf("�v���Z�X���I�����܂�\n");

	if (!pGameObjectAdmin)
	{
		printf("NullPtrException in Scene::TerminateScene()\n");
		return -1;
	}
	pGameObjectAdmin -> ClearAllGameObject();
	
	DxLib_End();

	return 0;
}

// �Q�[�����[�v�𑱂������
bool Scene::CanGameLoop()
{
	if (ProcessMessage() == -1)
	{
		printf("DxLib���ŃG���[���������܂����BProcessMessage() = -1\n");
		return false;
	}

	return true;
}