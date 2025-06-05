#include "Sprite.h"
#include "DxLib.h"
#include "UnityScale.h"

Sprite::Sprite()
{
	handle = -1;
	offset = Vector2{ };
}
void Sprite::SetInitalState_Sprite(int handle, Vector2 offset)
{
	Sprite::handle = handle;
	Sprite::offset = offset;
}

void Sprite::Execute()
{

}
void Sprite::Render()
{
	Vector2 graphPos = UnityScale::ParseToPixel(transform.position);
	int x = graphPos.x - offset.x;
	int y = graphPos.y - offset.y;
	DrawGraph(x, y, handle, true);
}
