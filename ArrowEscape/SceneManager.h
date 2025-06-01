#pragma once
#include <memory>
#include "Scene.h"

class SceneManager
{
public:

	int SwitchScene(std::unique_ptr<Scene>&& nextScene);

	int UpdateCurrentScene();

	bool CanGameLoop();

	int TerminateScene_GameExit();

private:

	std::unique_ptr<Scene> currentScene;

};
