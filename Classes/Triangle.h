#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle
{
	float baseLength;
	float height;
public : 
	// Trangle contstructor
	Triangle();
	// Triangle constructor with paramaters
	Triangle(float base, float height);
	// Set baselength of Triangle
	void setLength(float x);
	// set height of Triangle
	void setHeight(float x);
	// Get baseLength of Triangle
	float getLength() const;
	// get height of Triangle
	float getHeight() const;
	// get area of Triangle
	float getArea() const;
};

#endif // TRIANGLE_H