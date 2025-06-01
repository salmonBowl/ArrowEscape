#pragma once
#include <memory>
#include "GameObjectAdmin.h"

/*
	Scene.h
	Scene����邽�߂̒��ۊ��N���X
*/
class Scene
{
public:
	Scene();

	virtual int InitScene();
	virtual int TerminateScene();
	virtual int UpdateScene();
	bool CanGameLoop();

protected:
	std::unique_ptr<GameObjectAdmin> pGameObjectAdmin = nullptr;
};
