#pragma once

class Mathf
{
public:
	static int Round(float value);
	static int Floor(float value);
	static int Ceil(float value);
	static float Clamp(float value, float min, float max);
	static void SetClamp(float& value, float min, float max);
	static float Clamp01(float value);
	static float ValueOrMore(float value1, float value2);
	static float ValueOrLess(float value1, float value2);
};