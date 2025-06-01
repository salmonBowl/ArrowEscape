#include "GameObjectAdmin.h"

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

void GameObjectAdmin::UpdateAllGameObject()
{
	for (auto& pGameObject : pGameObjects)
	{
		if (!pGameObject) continue;

		pGameObject->Execute();
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

void GameObjectAdmin::Instantiate(std::unique_ptr<GameObject>&& gameObject)
{
	if (!gameObject)
	{
		printf("NullPtrException : GameObjectAdmin::Instantiate()\n");
		return;
	}

	Transform transform = Transform();

	gameObject->SetInitalState(transform);

	StoreInGameObjectArray(gameObject);
}
void GameObjectAdmin::Instantiate(std::unique_ptr<GameObject>&& gameObject, Vector2f pos)
{
	if (!gameObject)
	{
		printf("NullPtrException : GameObjectAdmin::Instantiate()\n");
		return;
	}

	Transform transform = Transform();
	transform.position = pos;

	gameObject->SetInitalState(transform);

	StoreInGameObjectArray(gameObject);
}
void GameObjectAdmin::Instantiate(std::unique_ptr<GameObject>&& gameObject, Transform transform)
{
	if (!gameObject)
	{
		printf("NullPtrException : GameObjectAdmin::Instantiate()\n");
		return;
	}

	gameObject->SetInitalState(transform);

	StoreInGameObjectArray(gameObject);
}
bool GameObjectAdmin::StoreInGameObjectArray(std::unique_ptr<GameObject>& storeObject)
{
	// �z��̋󂢂Ă���ꏊ��GameObject���i�[
	for (auto& pGameObject : pGameObjects)
	{
		if (!pGameObject)
		{
			pGameObject = std::move(storeObject);

			return true;
		}
	}

	printf("Instantiate�Ɏ��s���܂��� : GameObject�̍ő�e�ʂɒB���Ă��܂�\n");
	return false;
}