#include "SceneManager.h"

int SceneManager::SwitchScene(std::unique_ptr<Scene>&& nextScene)
{
	if (!nextScene) return -1;

	if (currentScene)
	{
		currentScene->TerminateScene();
	}

	// Scene‚ğ¶¬E‰Šú‰»
	int retval = nextScene->InitScene();

	// currentScene‚ğV‚µ‚¢Scene‚É‚·‚é
	currentScene = move(nextScene);

	return retval;
}
int SceneManager::UpdateCurrentScene()
{
	if (!currentScene) return -1;

	int retval = currentScene->UpdateScene();

	return retval;
}
bool SceneManager::CanGameLoop()
{
	if (!currentScene) return false;

	bool retval = currentScene->CanGameLoop();

	return retval;
}


int SceneManager::TerminateScene_GameExit()
{
	if (!currentScene) return -1;

	int retval = currentScene->TerminateScene();

	return retval;
}
