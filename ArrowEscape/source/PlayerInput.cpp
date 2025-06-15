#include "PlayerInput.h"

#include <Windows.h>
#include "DxLib.h"

PlayerInput::PlayerInput()
{
	parseKeyCode =
	{
		{ KeyCode::ArrowUp, KEY_INPUT_UP },
		{ KeyCode::ArrowDown, KEY_INPUT_DOWN },
		{ KeyCode::ArrowRight, KEY_INPUT_RIGHT },
		{ KeyCode::ArrowLeft, KEY_INPUT_LEFT },
		{ KeyCode::W, KEY_INPUT_W },
		{ KeyCode::S, KEY_INPUT_S },
		{ KeyCode::A, KEY_INPUT_A },
		{ KeyCode::D, KEY_INPUT_D },
		{ KeyCode::Space, KEY_INPUT_SPACE }
	};
	ZeroMemory(prevKeyBuffer, sizeof(char) * 256);
	ZeroMemory(currentKeyBuffer, sizeof(char) * 256);
}

void PlayerInput::Update()
{
	// Bufferのフレームを進める
	memcpy(prevKeyBuffer, currentKeyBuffer, sizeof(char) * 256);

	//現在フレームを取得
	GetHitKeyStateAll(currentKeyBuffer);
}

bool PlayerInput::PrevDown(KeyCode keyCode) { return prevKeyBuffer[parseKeyCode[keyCode]] == 0; }
bool PlayerInput::CurrentDown(KeyCode keyCode) { return currentKeyBuffer[parseKeyCode[keyCode]] == 0; }

bool PlayerInput::GetKey(KeyCode keyCode)
{
	if (PrevDown(keyCode) && CurrentDown(keyCode))
		return true;
	return false;
}
bool PlayerInput::GetKeyDown(KeyCode keyCode)
{
	if (PrevDown(keyCode) == false && CurrentDown(keyCode))
		return true;
	return false;
}

float PlayerInput::GetAxisRaw(std::string text)
{
	if (text == "Horizontal")
	{
		float moveX = 0;
		
		if (GetKey(KeyCode::ArrowRight) || GetKey(KeyCode::D))
			moveX++;
		if (GetKey(KeyCode::ArrowLeft) || GetKey(KeyCode::A))
			moveX--;

		return moveX;
	}
	else if (text == "Vertical")
	{
		float moveY = 0;

		if (GetKey(KeyCode::ArrowUp) || GetKey(KeyCode::W))
			moveY++;
		if (GetKey(KeyCode::ArrowDown) || GetKey(KeyCode::S))
			moveY--;

		return moveY;
	}

	return 0;
}