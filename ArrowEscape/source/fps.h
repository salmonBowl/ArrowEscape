#pragma once

#include <cstdint>
#include "EnterValue.h"
#include "SingletonBase.h"

class FPS : public SingletonBase<FPS>
{
public:
	void FPSInit();  // FPS関係の初期化
	void FPSCheck(); // FPS計測
	void FPSDraw();  // FPS描画
	void FPSWait();  // 待機

private:
	// 設定したいFPS
	const int GameFPS = EnterValue::GameFPS;

	const float MicroSecond = 1000000.0f; // 1マイクロ秒
	const float MillSecond = 1000.0f;    // 1ミリ秒
	const float WaitTimeMill = 3000;    // 最大で待てるミリ数

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

	FPSData fps;
};