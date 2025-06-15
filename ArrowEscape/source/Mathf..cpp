#include <math.h>
#include "Mathf.h"

int Mathf::Round(float value)
{
	return (int)round(value);
}
int Mathf::Floor(float value)
{
	return (int)floor(value);
}
int Mathf::Ceil(float value)
{
	return (int)ceil(value);
}
float Mathf::Clamp(float value, float min, float max)
{
	if (max < min)
	{
		(max, min) = (min, max);
	}
	value = ValueOrMore(value, min);
	value = ValueOrLess(value, max);
	return value;
}
void Mathf::SetClamp(float& value, float min, float max)
{
	value = Clamp(value, min, max);
}
float Mathf::Clamp01(float value)
{
	return Clamp(value, 0, 1);
}
float Mathf::ValueOrMore(float value1, float value2) // Mathf.Max
{
	if (value1 < value2)
		value1 = value2;
	return value1;
}
float Mathf::ValueOrLess(float value1, float value2) // Mathf.Min
{
	if (value1 < value2)
		value2 = value1;
	return value2;
}