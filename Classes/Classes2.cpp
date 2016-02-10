/*#include <iostream>
#include <assert.h>
#include <cmath>

class Square
{
	float sideLength;
public : 
	void setLength(float x);
	float getLength() const;
	float getArea() const;
};

void Square::setLength(float x)
{
	assert(x > 0);
	sideLength = x;
}

float Square::getLength() const
{
	return sideLength;
}

float Square::getArea() const
{
	return pow(sideLength, 2);
}

void main()
{
	Square example1;
	example1.setLength(5.0f);
	float x = example1.getLength();
	float y = example1.getArea();
}*/