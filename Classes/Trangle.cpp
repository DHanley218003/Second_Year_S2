#include "Triangle.h"
#include <assert.h>

Triangle::Triangle()
{
	baseLength = 1.0f;
	height = 1.0f;
}

Triangle::Triangle(float base, float xheight)
{
	baseLength = base;
	height = xheight;
}

void Triangle::setLength(float x)
{
	assert(x > 0);
	baseLength = x;
}

void Triangle::setHeight(float x)
{
	assert(x > 0);
	height = x;
}

float Triangle::getHeight() const
{
	return height;
}

float Triangle::getLength() const
{
	return baseLength;
}

float Triangle::getArea() const
{
	return (height * baseLength) / 2;
}
