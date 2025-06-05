#pragma once
#include <memory>
#include <array>
#include "GameObject.h"
#include "EnterValue.h"
#include "Transform.h"
#include "ImageManager.h"

/*
	ŠeScene‚ÌAdmin‚Ì‚½‚ß‚Ì’ŠÛŠî’êƒNƒ‰ƒX
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

	void Instantiate(AllGraphName name);
	void Instantiate(AllGraphName name, Vector2f pos);
	void Instantiate(AllGraphName name, Transform transform);

private:

	bool StoreInGameObjectArray(std::unique_ptr<GameObject>& gameObject);

};
