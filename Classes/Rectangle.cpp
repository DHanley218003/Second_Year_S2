#include "Rectangle.h"
#include <assert.h>

Rectangle::Rectangle()
{
	sideLength = 1.0f;
	sideWidth = 1.0f;
}

Rectangle::Rectangle(float length, float width)
{
	sideLength = length;
	sideWidth = width;
}

void Rectangle::setLength(float x)
{
	assert(x > 0);
	sideLength = x;
}

void Rectangle::setWidth(float x)
{
	assert(x > 0);
	sideWidth = x;
}

float Rectangle::getLength() const
{
	return sideLength;
}

float Rectangle::getWidth() const
{
	return sideWidth;
}

float Rectangle::getArea() const
{
	return sideLength * sideWidth;
}

