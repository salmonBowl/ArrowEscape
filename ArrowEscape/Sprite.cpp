#include "Sprite.h"
#include "DxLib.h"
#include "UnityScale.h"
#include "Image.h"

Sprite::Sprite()
{
	offset = Vector2{};
}
Sprite::Sprite(const char* fileName, float imageMagnification, Vector2 offset)
{
	handle = Image::Instance()->LoadGraph(fileName, imageMagnification);
	Sprite::offset = offset;
}
Sprite::~Sprite()
{
	DeleteGraph(handle);
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
