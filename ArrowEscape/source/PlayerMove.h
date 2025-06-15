#pragma once
#include "Vector2.h"
#include "Transform.h"
#include "Background.h"

class PlayerMove
{
private:
    Vector2f myVelocity;
    float moveSpeed;
    Background background;

    float playerWidth;
    float feetLength;

    float speed;
        float ratio_airmove;
    float jumpPower;
    PlayerJumpCharge jumpcharge;
    float jumpChargeSpeed;

    float stageWidth;
    float groundLevel;
    Vector2f gravityForce;

    PlayerInput input;

    /*
        Jump(キー入力、地面に接地しているか)
            ジャンプをする関数ではなくUpdateの中で動く、ジャンプに関する色々な処理
            grondedがfalseだと2段ジャンプの挙動になります
     */
    void Jump(bool grounded);

    // 地面に設置しているかを返す関数
    bool Grounded(Vector2f myPosition) const;

public:
    PlayerMove();

    void Execute(Transform& transform);

}