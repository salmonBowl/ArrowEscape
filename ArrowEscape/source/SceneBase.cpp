#include "SceneBase.h"

#include "DxLib.h"
#include "fps.h"
#include "GameObjectAdmin.h"
#include "GameWindow.h"
//#include "SceneManager.h"
#include "ImageManager.h"


SceneBase::SceneBase()
{

}

int SceneBase::InitScene()
{
	// 全体開始処理・終了処理をScene内でやっているせいでScene切り替えのたびに重い処理が走ることになっている
	// いつか要修正

	ChangeWindowMode(true);
	SetGraphMode(GameWindow::CoordinateWidth, GameWindow::CoordinateHeight, 32);
	SetWindowSize(GameWindow::WindowWidth, GameWindow::WindowHeight);
	if (DxLib_Init() == -1)
	{
		printf("DxLibの初期化でエラーが発生したため終了します\n");
		return -1;
	}
	// 使う画像の読み込み
	ImageManager::Instance()->LoadAll();


	// ここから各Sceneの処理

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

	// 更新処理
	
	pGameObjectAdmin->ExecuteAllGameObject();
	
	// 描画処理

	ClearDrawScreen();
	SetDrawScreen(DX_SCREEN_BACK);

	pGameObjectAdmin->RenderAllGameObject();

	FPS::Instance()->FPSWait();

	ScreenFlip();

	return 0;
}
int SceneBase::TerminateScene()
{
	printf("プロセスを終了します\n");

	if (!pGameObjectAdmin)
	{
		printf("NullPtrException in Scene::TerminateScene()\n");
		return -1;
	}

	// GameObjectを開放
	pGameObjectAdmin -> ClearAllGameObject();
	// 今までのLoadGraphで作られたhandleを開放
	ImageManager::Instance()->ReleaseAll();
	
	DxLib_End();

	return 0;
}

// ゲームループを続ける条件
bool SceneBase::CanGameLoop()
{
	if (ProcessMessage() == -1)
	{
		printf("DxLib内でエラーが発生しました。ProcessMessage() = -1\n");
		return false;
	}

	return true;
}