#include "PlayerJumpCharge.h"

void PlayerJumpCharge::SetValue(float value)
{
    // チャージが完了したらエフェクトを出す
    if (PlayerJumpCharge::value < 1 && value == 1)
    {
        PlayerEventManager.Instance().Event("ChargeFulled");
    }

    PlayerJumpCharge::value = value;
}