#include "fps.h"
#include "DxLib.h"

FPS::FPSData FPS::fps;

// ������
void FPS::FPSInit()
{
	// PC�N�����猻�݂܂ł̎��Ԃ��}�C�N���b�Ŏ擾
	fps.FirstTakeTime = GetNowHiPerformanceCount();

	// �l�̏�����
	fps.NowTakeTime = fps.FirstTakeTime;
	fps.OldTakeTime = fps.FirstTakeTime;
	fps.deltaTime = 0.000001f;
	fps.frameCount = 1;
	fps.avarage = 0.0f;

	return;
}

// FPS�v��
void FPS::FPSCheck()
{
	// ���݂̎������擾
	fps.NowTakeTime = GetNowHiPerformanceCount();

	// deltaTime���v�Z�����݂̎�����ۑ�
	fps.deltaTime = (fps.NowTakeTime - fps.OldTakeTime) / MicroSecond;
	fps.OldTakeTime = fps.NowTakeTime;

	// (FPS)���̃t���[���ɉ��b���������̂��v�Z
	if (fps.frameCount == GameFPS)
	{
		// ���������b�� (�}�C�N���b)
		LONGLONG TotalFrameTime = fps.NowTakeTime - fps.FirstTakeTime;

		// FPS���ϒl
		fps.avarage = (GameFPS * MicroSecond) / TotalFrameTime;

		// ���̌v���̂��߂̃��Z�b�g
		fps.FirstTakeTime = GetNowHiPerformanceCount();
		fps.frameCount = 1;
	}
	else // �t���[�����̃J�E���g�A�b�v
	{
		fps.frameCount++;
	}

	return;
}

// �v������FPS�̕`��
void FPS::FPSDraw()
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "fps:%3.1f", fps.avarage);
	return;
}

// FPS��ۂ��߂ɑҋ@
void FPS::FPSWait()
{
	float waitms = 0;

	// �ҋ@���Ԃ̌v�Z
	// �����ł̓}�C�N���b���v�Z�����
	waitms =
		MicroSecond * fps.frameCount / GameFPS   // ���z�̎���
		- (fps.NowTakeTime - fps.FirstTakeTime); // ���ۂ̎���

	waitms /= MillSecond; // �}�C�N���b���~���b

	// �v�Z�������Ԃ����ҋ@
	if (0 < waitms)
	{
		// �ҋ@���Ԃ��������Ȃ��悤��
		if (WaitTimeMill < waitms)
		{
			waitms = (float)WaitTimeMill;
		}
		// �ҋ@
		WaitTimer((int)waitms);
	}

	return;
}
