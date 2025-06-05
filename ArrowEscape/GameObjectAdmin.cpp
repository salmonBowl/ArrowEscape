#include "GameObjectAdmin.h"

#include <memory>
#include "GameObjectFactory.h"
#include "Sprite.h"

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

void GameObjectAdmin::Instantiate(AllGraphName name)
{
	Transform transform = Transform();

	Instantiate(name, transform);
}
void GameObjectAdmin::Instantiate(AllGraphName name, Vector2f pos)
{
	Transform transform = Transform();
	transform.position = pos;

	Instantiate(name, transform);
}
void GameObjectAdmin::Instantiate(AllGraphName name, Transform transform)
{
	auto pGameObject = GameObjectFactory::Create(name);
	if (!pGameObject) {
		printf("オブジェクトの生成に失敗しました。おそらくGameObjectFactoryに定義がありません。\n");
		return;
	}

	auto& info = ImageManager::Instance()->GetInfo(name);

	pGameObject->SetInitalState(transform);
	
	// GameObjectをSpriteに変換できるならoffsetを指定
	// gameObjectの所有はpGameObjectなのでこれで大丈夫
	if (Sprite* sprite = dynamic_cast<Sprite*>(pGameObject.get()))
	{
		sprite->SetInitalState_Sprite(info.handle, info.offset);
	}

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