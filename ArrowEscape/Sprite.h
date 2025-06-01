#pragma once
#include "GameObject.h"

class Sprite : public GameObject
{
public:
	Sprite();
	Sprite(const char* fileName, float imageMagnification, Vector2 offset);
	~Sprite();

	//void Init() override;
	virtual void Execute() override;
	void Render() override;

protected:
	int handle = -1;
	Vector2 offset;
};