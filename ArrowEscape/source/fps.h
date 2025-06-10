#pragma once

#include <cstdint>
#include "EnterValue.h"
#include "SingletonBase.h"

class FPS : public SingletonBase<FPS>
{
public:
	void FPSInit();  // FPS�֌W�̏�����
	void FPSCheck(); // FPS�v��
	void FPSDraw();  // FPS�`��
	void FPSWait();  // �ҋ@

private:
	// �ݒ肵����FPS
	const int GameFPS = EnterValue::GameFPS;

	const float MicroSecond = 1000000.0f; // 1�}�C�N���b
	const float MillSecond = 1000.0f;    // 1�~���b
	const float WaitTimeMill = 3000;    // �ő�ő҂Ă�~����

	// �\����FPS : FPS�̌v�Z�Ɏg��
	struct FPSData
	{
		int64_t FirstTakeTime;
		int64_t NowTakeTime;
		int64_t OldTakeTime;
		float deltaTime;
		int frameCount;
		float avarage;
	};

	FPSData fps;
};