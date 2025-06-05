#include "GameObjectAdmin.h"

#include <memory>
#include "GameObjectFactory.h"

GameObjectAdmin::GameObjectAdmin()
{

}

void GameObjectAdmin::InitAllGameObject()
{
	for (auto& pGameObject : pGameObjects)
	{
		if (!pGameObject) continue;

		pGameObject->Init();
	}
}

void GameObjectAdmin::ExecuteAllGameObject()
{
	for (auto& pGameObject : pGameObjects)
	{
		if (!pGameObject) continue;

		pGameObject->Execute();
	}
}
void GameObjectAdmin::RenderAllGameObject()
{
	for (auto& pGameObject : pGameObjects)
	{
		if (!pGameObject) continue;

		pGameObject->Render();
	}
}

void GameObjectAdmin::ClearAllGameObject()
{
	for (auto& pGameObject : pGameObjects)
	{
		if (!pGameObject) continue;

		pGameObject.reset();
	}
}

void GameObjectAdmin::Instantiate(GameObjectType name)
{
	Transform transform = Transform();

	Instantiate(name, transform);
}
void GameObjectAdmin::Instantiate(GameObjectType name, Vector2f pos)
{
	Transform transform = Transform();
	transform.position = pos;

	Instantiate(name, transform);
}
void GameObjectAdmin::Instantiate(GameObjectType name, Transform transform)
{
	auto pGameObject = GameObjectFactory::Instance()->CreateGameObject(name);
	if (!pGameObject) {
		printf("オブジェクトの生成に失敗しました。おそらくGameObjectFactoryに定義がありません。\n");
		return;
	}

	pGameObject->SetInitalState(transform);
	
	StoreInGameObjectArray(pGameObject);
}
bool GameObjectAdmin::StoreInGameObjectArray(std::unique_ptr<GameObject>& storeObject)
{
	// 配列の空いている場所にGameObjectを格納
	for (auto& pGameObject : pGameObjects)
	{
		if (!pGameObject)
		{
			pGameObject = std::move(storeObject);

			return true;
		}
	}

	printf("Instantiateに失敗しました : GameObjectの最大容量に達しています\n");
	return false;
}