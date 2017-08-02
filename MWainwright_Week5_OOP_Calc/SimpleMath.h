#pragma once
class SimpleMath
{
public:
	SimpleMath();
	~SimpleMath();
};

class Addition :
	public SimpleMath
{
public:
	Addition();
	~Addition();
	double add(double, double);
};

class Subtration :
	public SimpleMath
{
public:
	Subtration();
	~Subtration();
	double subtract(double, double);
};

class Multiplication :
	public SimpleMath
{
public:
	Multiplication();
	~Multiplication();
	double multiply(double, double);	
};

class Division :
	public SimpleMath
{
public:
	Division();
	~Division();
	double divide(double, double);
};