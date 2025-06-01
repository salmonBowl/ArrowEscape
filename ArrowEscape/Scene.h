#pragma once
#include <memory>
#include "GameObjectAdmin.h"

/*
	Scene.h
	Scene‚ğì‚é‚½‚ß‚Ì’ŠÛŠî’êƒNƒ‰ƒX
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
