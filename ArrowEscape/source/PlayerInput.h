#pragma once

class PlayerInput
{
public :

	PlayerInput();

	void Update();

	const float& X = x;
	const bool& JumpTriggered = jumpTriggered;

private :

	float x;
	bool jumpTriggered;
};