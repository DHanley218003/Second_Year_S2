#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
	float sideLength;
	float sideWidth;
public : 
	Rectangle();
	Rectangle(float length, float width);
	void setLength(float x);
	void setWidth(float x);
	float getLength() const;
	float getWidth() const;
	float getArea() const;
};

#endif // RECTANGLE_H