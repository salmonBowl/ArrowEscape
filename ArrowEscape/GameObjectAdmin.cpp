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
		printf("�I�u�W�F�N�g�̐����Ɏ��s���܂����B�����炭GameObjectFactory�ɒ�`������܂���B\n");
		return;
	}

	auto& info = ImageManager::Instance()->GetInfo(name);

	pGameObject->SetInitalState(transform);
	
	// GameObject��Sprite�ɕϊ��ł���Ȃ�offset���w��
	// gameObject�̏��L��pGameObject�Ȃ̂ł���ő��v
	if (Sprite* sprite = dynamic_cast<Sprite*>(pGameObject.get()))
	{
		sprite->SetInitalState_Sprite(info.handle, info.offset);
	}

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