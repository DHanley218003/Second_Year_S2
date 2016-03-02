#ifndef SQUARE_H
#define SQUARE_H

class Square
{
	float sideLength;
public : 
	Square();
	Square(float length);
	void setLength(float x);
	float getLength() const;
	float getArea() const;
};

#endif // SQUARE_H
