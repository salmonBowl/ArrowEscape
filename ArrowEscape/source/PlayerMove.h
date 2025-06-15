#pragma once
#include "Vector2.h"
#include "Transform.h"
#include "Background.h"
#include "PlayerJumpCharge.h"
#include "PlayerInput.h"

class PlayerMove
{
public:
    PlayerMove();

    void Execute(Transform& transform);

private:
    PlayerInput input;
    PlayerJumpCharge jumpcharge;

    Vector2f myVelocity;
    float moveSpeed;
    Background background;

    float playerWidth;
    float feetLength;

    float speed;
    float ratio_airmove;
    float jumpPower;
    float jumpChargeSpeed;

    float stageWidth;
    float groundLevel;
    Vector2f gravityForce;


    /*
        Jump(キー入力、地面に接地しているか)
            ジャンプをする関数ではなくUpdateの中で動く、ジャンプに関する色々な処理
            grondedがfalseだと2段ジャンプの挙動になります
     */
    void Jump(bool grounded);
    float IncreaseJumpCharge(float value) const;

    // 地面に設置しているかを返す関数
    bool Grounded(Vector2f myPosition) const;
};