#pragma once
#include <memory>
#include "SceneBase.h"

class SceneManager
{
public:

	int SwitchScene(std::unique_ptr<SceneBase>&& nextScene);

	int UpdateCurrentScene();

	bool CanGameLoop();

	int TerminateScene_GameExit();

private:

	std::unique_ptr<SceneBase> currentScene;

};
