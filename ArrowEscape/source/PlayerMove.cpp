#include "PlayerMove.h"

#include "PlayerInput.h"
#include "Mathf.h"

PlayerMove::PlayerMove()
{
    stageWidth = background.Width;
    groundLevel = background.GroundLevel;
    gravityForce = background.GravityForce;
    moveSpeed = 4;
    myVelocity = Vector2f{ 0, 0 };
}

void PlayerMove::Execute(Transform& transform)
{
    input.Update();

    float inputX = input.X;
    bool jumpTriggered = input.JumpTriggered;

    // 更新前と更新後のPlayerの座標
    Vector2f currentPosition = transform.position;
    Vector2f nextPosition = transform.position;

    if (Grounded(currentPosition))
    {
        // このフレームで地上なら

        printf("Player Grounded\n");

        // velocityの計算
        myVelocity.x = input.X * moveSpeed;
        myVelocity.y = 0;

        jumpcharge.SetValue(Mathf::Clamp01(IncreaseJumpCharge(jumpcharge.Value)));

        if (jumpTriggered)
        {
            // 通常のジャンプ
            Jump(true);
        }
    }
    else
    {
        // このフレームで空中なら
        
        // velocityの計算
        myVelocity.x = input.X * moveSpeed;
        myVelocity = AddVector2(myVelocity, background.GravityForce); // 自然落下

        if (jumpTriggered)
        {
            // 2段ジャンプ
            Jump(false);
        }
    }

    // velocityを加算
    nextPosition.x = myVelocity.x * Time.deltaTime;
    nextPosition.y = myVelocity.y * Time.deltaTime;


    // 位置補正
    // 画面外に行くならxを補正
    float moveRange_half = (stageWidth - playerWidth) / 2;
    nextPosition.x = Mathf::Clamp(nextPosition.x, -moveRange_half, moveRange_half);
    // 地面にめり込むならyを補正
    if (Grounded(nextPosition))
    {
        nextPosition.y = groundLevel + feetLength;
    }

    // 座標を更新
    transform.position = nextPosition;
}
float PlayerMove::IncreaseJumpCharge(float value) const
{
    float adjust = 0.05f;
    float increaseDelta = (jumpChargeSpeed * (1 - adjust)) + ((1 - value) * adjust);
    return value + increaseDelta;
}

/*
    Jump(キー入力、地面に接地しているか)
        ジャンプをする関数ではなくUpdateの中で動く、ジャンプに関する色々な処理
        grondedがfalseだと2段ジャンプの挙動になります
 */
void PlayerMove::Jump(bool grounded)
{
    // 通常のジャンプ処理
    if (grounded)
    {
        // ジャンプによりjumpChargeを最大0.5だけ消費

        myVelocity.y += Mathf::ValueOrMore(jumpcharge.Value, 0.5f) * jumpPower;
        jumpcharge.SetValue(Mathf::ValueOrMore(jumpcharge.Value - 0.5f, 0));
    }
    else // 2段ジャンプ
    {
        if (0.4f < jumpcharge.Value)
        {
            myVelocity.y = 0.5f * jumpPower;
            jumpcharge.SetValue(0);
        }
    }
}
bool PlayerMove::Grounded(Vector2f myPosition) const
{
    // Playerの足の高さ
    float playerAnkleHight = myPosition.y - feetLength;

    // Playerが地面の高さ以下ならtrueを返す
    float adjust = 0.001f;
    return playerAnkleHight - adjust < groundLevel;
}
