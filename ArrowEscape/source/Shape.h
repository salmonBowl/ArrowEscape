#pragma once
#include "GameObject.h"

class Shape : public GameObject
{
public:
	enum ShapeType
	{
		Box,
		Circle
	};

	Shape(ShapeType shapeType, Vector2 pos);
	~Shape();

protected:

	//void Init() override;
	//void Terminate() override;
	void Render() override;
};