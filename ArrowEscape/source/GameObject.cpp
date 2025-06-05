#include "GameObject.h"
#include <stdio.h>

void GameObject::Init()
{
	transform.position = initalState.transform.position;
}
void GameObject::Terminate()
{

}

void GameObject::SetActive(bool value)
{
	if (isActive == value)
	{
		printf("警告 : SetActive(%s)が実行されましたが、その必要はありません\n", value? "true" : "false");
	}
	isActive = value;
}
void GameObject::SetVisible(bool value)
{
	isVisible = value;
}

void GameObject::SetInitalState(Transform transform)
{
	initalState.transform = transform;
}