#include "Player.h"

#include <memory>
#include "ImageManager.h"
#include "EnterValue.h"
#include "Input.h"

Player::Player()
{
	moveSpeed = 4;
}

void Player::Execute()
{
	auto& input = *Input::Instance();
	
	/*
	float inputX = 0;
	if (input.GetKey(KeyCode::ArrowRight))
		inputX++;
	if (input.GetKey(KeyCode::ArrowLeft))
		inputX--;

	transform.position.x += inputX * moveSpeed;
	*/

	transform.position.x += input.GetAxisRaw("Horizontal") * moveSpeed;
	velocity += input.GetAxisRaw("Horizontal") * moveSpeed;

}