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
        Jump(�L�[���́A�n�ʂɐڒn���Ă��邩)
            �W�����v������֐��ł͂Ȃ�Update�̒��œ����A�W�����v�Ɋւ���F�X�ȏ���
            gronded��false����2�i�W�����v�̋����ɂȂ�܂�
     */
    void Jump(bool grounded);
    float IncreaseJumpCharge(float value) const;

    // �n�ʂɐݒu���Ă��邩��Ԃ��֐�
    bool Grounded(Vector2f myPosition) const;
};