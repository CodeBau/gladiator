#include"linear_function.h"

float linear_function(float y1, float x1, float y2, float x2, float x3)
{
	float a=(y2-y1)/(x2-x1);
	float b=y2-a*x2;
	float y3 = a * x3 +b ;

	return y3;
}