#pragma once

#include <cstdint>
#include "EnterValue.h"

class FPS
{
public:
	static void FPSInit();  // FPS関係の初期化
	static void FPSCheck(); // FPS計測
	static void FPSDraw();  // FPS描画
	static void FPSWait();  // 待機

private:
	// 設定したいFPS
	static const int GameFPS = EnterValue::GameFPS;

	static constexpr float MicroSecond = 1000000.0f; // 1マイクロ秒
	static constexpr float MillSecond = 1000.0f;    // 1ミリ秒
	static constexpr float WaitTimeMill = 3000;    // 最大で待てるミリ数

	// 構造体FPS : FPSの計算に使う
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