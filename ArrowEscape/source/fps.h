#pragma once

#include <cstdint>
#include "EnterValue.h"

class FPS
{
public:
	static void FPSInit();  // FPS�֌W�̏�����
	static void FPSCheck(); // FPS�v��
	static void FPSDraw();  // FPS�`��
	static void FPSWait();  // �ҋ@

private:
	// �ݒ肵����FPS
	static const int GameFPS = EnterValue::GameFPS;

	static constexpr float MicroSecond = 1000000.0f; // 1�}�C�N���b
	static constexpr float MillSecond = 1000.0f;    // 1�~���b
	static constexpr float WaitTimeMill = 3000;    // �ő�ő҂Ă�~����

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

	static FPSData fps;
};