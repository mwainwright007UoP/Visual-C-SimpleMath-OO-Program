#include "stdafx.h"
#include "SimpleMath.h"


SimpleMath::SimpleMath()
{
}


SimpleMath::~SimpleMath()
{
}


Addition::Addition()
{
}

Addition::~Addition()
{
}
double Addition::add(double x, double y){
	double result = x + y;
	return result;
}



Subtration::Subtration()
{
}

Subtration::~Subtration()
{
}
double Subtration::subtract(double x, double y){
	double result = x - y;
	return result;
}

Multiplication::Multiplication()
{
}

Multiplication::~Multiplication()
{
}
double Multiplication::multiply(double x, double y){
	double result = x * y;
	return result;
}

Division::Division()
{
}

Division::~Division()
{
}
double Division::divide(double x, double y){
	double result;
	if (y !=0)		// verifying the divisor is not 0
	{
		result = x / y;
	}
	else
	{
		result = 0;
	}
	return result;
}
