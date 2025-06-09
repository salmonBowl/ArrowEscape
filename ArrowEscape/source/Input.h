#pragma once
#include "SingletonBase.h"
#include <unordered_map>
#include <string>

enum class KeyCode
{
	ArrowUp, ArrowDown, ArrowRight, ArrowLeft,
	W, S, A, D, Space
};

class Input : SingletonBase<Input>
{
	friend class SingletonBase<Input>;
public :

	void Update();

	bool GetKey(KeyCode keycode);
	bool GetKeyDown(KeyCode keycode);
	float GetAxisRaw(std::string Horizontal_or_Vertical);

private :

	Input();

	std::unordered_map<KeyCode, int> parseKeyCode;
	char prevKeyBuffer[256];
	char currentKeyBuffer[256];

	bool PrevDown(KeyCode keycode);
	bool CurrentDown(KeyCode keycode);
};