#include "PlayerInput.h"
#include "Input.h"

PlayerInput::PlayerInput()
{
	x = 0;
	jumpTriggered = false;
}
void PlayerInput::Update()
{
	Input& input = *Input::Instance();
	
	x = input.GetAxisRaw("Horizontal");

	jumpTriggered = input.GetKeyDown(KeyCode::Space)
		|| input.GetKeyDown(KeyCode::ArrowUp)
		|| input.GetKeyDown(KeyCode::W);
}