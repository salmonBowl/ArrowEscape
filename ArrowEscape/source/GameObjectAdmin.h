#pragma once
#include <memory>
#include <array>
#include "GameObject.h"
#include "EnterValue.h"
#include "Transform.h"

/*
	�eScene��Admin�̂��߂̒��ۊ��N���X
*/

class GameObjectAdmin
{
public:
	GameObjectAdmin();

	virtual void InitAllGameObject();
	void ExecuteAllGameObject();
	void RenderAllGameObject();
	void ClearAllGameObject();

protected:

	std::array<std::unique_ptr<GameObject>, EnterValue::LimitNumOfGameObject> pGameObjects;

	void Instantiate(GameObjectType name);
	void Instantiate(GameObjectType name, Vector2f pos);
	void Instantiate(GameObjectType name, Transform transform);

private:

	bool StoreInGameObjectArray(std::unique_ptr<GameObject>& gameObject);

};
