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

    // �X�V�O�ƍX�V���Player�̍��W
    Vector2f currentPosition = transform.position;
    Vector2f nextPosition = transform.position;

    if (Grounded(currentPosition))
    {
        // ���̃t���[���Œn��Ȃ�

        printf("Player Grounded\n");

        // velocity�̌v�Z
        myVelocity.x = input.X * moveSpeed;
        myVelocity.y = 0;

        jumpcharge.SetValue(Mathf::Clamp01(IncreaseJumpCharge(jumpcharge.Value)));

        if (jumpTriggered)
        {
            // �ʏ�̃W�����v
            Jump(true);
        }
    }
    else
    {
        // ���̃t���[���ŋ󒆂Ȃ�
        
        // velocity�̌v�Z
        myVelocity.x = input.X * moveSpeed;
        myVelocity = AddVector2(myVelocity, background.GravityForce); // ���R����

        if (jumpTriggered)
        {
            // 2�i�W�����v
            Jump(false);
        }
    }

    // velocity�����Z
    nextPosition.x = myVelocity.x * Time.deltaTime;
    nextPosition.y = myVelocity.y * Time.deltaTime;


    // �ʒu�␳
    // ��ʊO�ɍs���Ȃ�x��␳
    float moveRange_half = (stageWidth - playerWidth) / 2;
    nextPosition.x = Mathf::Clamp(nextPosition.x, -moveRange_half, moveRange_half);
    // �n�ʂɂ߂荞�ނȂ�y��␳
    if (Grounded(nextPosition))
    {
        nextPosition.y = groundLevel + feetLength;
    }

    // ���W���X�V
    transform.position = nextPosition;
}
float PlayerMove::IncreaseJumpCharge(float value) const
{
    float adjust = 0.05f;
    float increaseDelta = (jumpChargeSpeed * (1 - adjust)) + ((1 - value) * adjust);
    return value + increaseDelta;
}

/*
    Jump(�L�[���́A�n�ʂɐڒn���Ă��邩)
        �W�����v������֐��ł͂Ȃ�Update�̒��œ����A�W�����v�Ɋւ���F�X�ȏ���
        gronded��false����2�i�W�����v�̋����ɂȂ�܂�
 */
void PlayerMove::Jump(bool grounded)
{
    // �ʏ�̃W�����v����
    if (grounded)
    {
        // �W�����v�ɂ��jumpCharge���ő�0.5��������

        myVelocity.y += Mathf::ValueOrMore(jumpcharge.Value, 0.5f) * jumpPower;
        jumpcharge.SetValue(Mathf::ValueOrMore(jumpcharge.Value - 0.5f, 0));
    }
    else // 2�i�W�����v
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
    // Player�̑��̍���
    float playerAnkleHight = myPosition.y - feetLength;

    // Player���n�ʂ̍����ȉ��Ȃ�true��Ԃ�
    float adjust = 0.001f;
    return playerAnkleHight - adjust < groundLevel;
}
