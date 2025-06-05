#pragma once
#include "Transform.h"

class GameObject
{
public:
	GameObject() = default;
	virtual ~GameObject() = default;

	void Init();
	void Terminate();
	virtual void Execute() = 0;
	virtual void Render() = 0;

	void SetActive(bool value);
	void SetVisible(bool value);

	void SetInitalState(Transform transform);

	const Transform& GetTransform() const { return transform; }
	const bool& GetActive() const { return isActive; }
	const bool& GetVisible() const { return isVisible; }

protected:

	Transform transform;
	bool isActive = true;
	bool isVisible = true;

	struct InitalState
	{
		Transform transform;
	};
	InitalState initalState;
};