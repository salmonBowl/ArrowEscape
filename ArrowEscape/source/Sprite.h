#pragma once
#include "GameObject.h"

class Sprite : public GameObject
{
public:
	Sprite();

	void SetInitalState_Sprite(int handle, Vector2 offset);

	//void Init() override;
	virtual void Execute() override;
	void Render() override;

protected:
	int handle;
	Vector2 offset;
};