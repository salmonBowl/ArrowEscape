#include "PlayerJumpCharge.h"

void PlayerJumpCharge::SetValue(float value)
{
    // �`���[�W������������G�t�F�N�g���o��
    if (PlayerJumpCharge::value < 1 && value == 1)
    {
        PlayerEventManager.Instance().Event("ChargeFulled");
    }

    PlayerJumpCharge::value = value;
}