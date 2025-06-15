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
        Jump(�L�[���́A�n�ʂɐڒn���Ă��邩)
            �W�����v������֐��ł͂Ȃ�Update�̒��œ����A�W�����v�Ɋւ���F�X�ȏ���
            gronded��false����2�i�W�����v�̋����ɂȂ�܂�
     */
    void Jump(bool grounded);

    // �n�ʂɐݒu���Ă��邩��Ԃ��֐�
    bool Grounded(Vector2f myPosition) const;

public:
    PlayerMove();

    void Execute(Transform& transform);

}