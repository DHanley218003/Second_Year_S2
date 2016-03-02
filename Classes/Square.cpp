#include <assert.h>
#include "Square.h"

Square::Square()
{
	sideLength = 1.0f;
}

Square::Square(float length)
{
	sideLength = length;
}

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
	return sideLength * sideLength;
}