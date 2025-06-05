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
		printf("�I�u�W�F�N�g�̐����Ɏ��s���܂����B�����炭GameObjectFactory�ɒ�`������܂���B\n");
		return;
	}

	pGameObject->SetInitalState(transform);
	
	StoreInGameObjectArray(pGameObject);
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