#include "fps.h"
#include "DxLib.h"

FPS::FPSData FPS::fps;

// 初期化
void FPS::FPSInit()
{
	// PC起動から現在までの時間をマイクロ秒で取得
	fps.FirstTakeTime = GetNowHiPerformanceCount();

	// 値の初期化
	fps.NowTakeTime = fps.FirstTakeTime;
	fps.OldTakeTime = fps.FirstTakeTime;
	fps.deltaTime = 0.000001f;
	fps.frameCount = 1;
	fps.avarage = 0.0f;

	return;
}

// FPS計測
void FPS::FPSCheck()
{
	// 現在の時刻を取得
	fps.NowTakeTime = GetNowHiPerformanceCount();

	// deltaTimeを計算し現在の時刻を保存
	fps.deltaTime = (fps.NowTakeTime - fps.OldTakeTime) / MicroSecond;
	fps.OldTakeTime = fps.NowTakeTime;

	// (FPS)枚のフレームに何秒かかったのか計算
	if (fps.frameCount == GameFPS)
	{
		// かかった秒数 (マイクロ秒)
		LONGLONG TotalFrameTime = fps.NowTakeTime - fps.FirstTakeTime;

		// FPS平均値
		fps.avarage = (GameFPS * MicroSecond) / TotalFrameTime;

		// 次の計測のためのリセット
		fps.FirstTakeTime = GetNowHiPerformanceCount();
		fps.frameCount = 1;
	}
	else // フレーム数のカウントアップ
	{
		fps.frameCount++;
	}

	return;
}

// 計測したFPSの描画
void FPS::FPSDraw()
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "fps:%3.1f", fps.avarage);
	return;
}

// FPSを保つために待機
void FPS::FPSWait()
{
	float waitms = 0;

	// 待機時間の計算
	// ここではマイクロ秒が計算される
	waitms =
		MicroSecond * fps.frameCount / GameFPS   // 理想の時間
		- (fps.NowTakeTime - fps.FirstTakeTime); // 実際の時間

	waitms /= MillSecond; // マイクロ秒→ミリ秒

	// 計算した時間だけ待機
	if (0 < waitms)
	{
		// 待機時間が長すぎないように
		if (WaitTimeMill < waitms)
		{
			waitms = (float)WaitTimeMill;
		}
		// 待機
		WaitTimer((int)waitms);
	}

	return;
}
