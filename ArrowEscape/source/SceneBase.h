#pragma once
#include <memory>
#include "GameObjectAdmin.h"

/*
	Scene.h
	Sceneを作るための抽象基底クラス
*/
class SceneBase
{
public:
	SceneBase();

	virtual int InitScene();
	virtual int TerminateScene();
	virtual int UpdateScene();
	bool CanGameLoop();

protected:
	std::unique_ptr<GameObjectAdmin> pGameObjectAdmin = nullptr;
};
