#include "SceneBase.h"
#include "DxLib.h"
#include "fps.h"
#include "GameObjectAdmin.h"
#include "GameWindow.h"
#include "SceneManager.h"

SceneBase::SceneBase()
{

}

int SceneBase::InitScene()
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

int SceneBase::UpdateScene()
{
	if (!pGameObjectAdmin)
	{
		printf("NullPtrException in Scene::Update()\n");
		return -1;
	}

	// �X�V����
	
	pGameObjectAdmin->ExecuteAllGameObject();
	
	// �`�揈��

	ClearDrawScreen();
	SetDrawScreen(DX_SCREEN_BACK);

	pGameObjectAdmin->RenderAllGameObject();

	FPS::FPSWait();

	ScreenFlip();

	return 0;
}
int SceneBase::TerminateScene()
{
	printf("�v���Z�X���I�����܂�\n");

	if (!pGameObjectAdmin)
	{
		printf("NullPtrException in Scene::TerminateScene()\n");
		return -1;
	}

	// GameObject���J��
	pGameObjectAdmin -> ClearAllGameObject();
	// ���܂ł�LoadGraph�ō��ꂽhandle���J��
	ImageManager::Instance()->ReleaseAll();
	
	DxLib_End();

	return 0;
}

// �Q�[�����[�v�𑱂������
bool SceneBase::CanGameLoop()
{
	if (ProcessMessage() == -1)
	{
		printf("DxLib���ŃG���[���������܂����BProcessMessage() = -1\n");
		return false;
	}

	return true;
}