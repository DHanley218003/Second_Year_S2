#include "Square.h"
#include "Triangle.h"
#include "Rectangle.h"
#include <iostream>

void main()
{
	Square s1;
	s1.setLength(5.0f);
	std::cout << "Square Area:" << s1.getArea() << "\nlength: " << s1.getLength() << std::endl << std::endl;

	Triangle t1;
	t1.setHeight(5.0f);
	t1.setLength(1.0f);
	std::cout << "Triangle1 Area: " << t1.getArea() << "\nheight: " << t1.getHeight() << "\nLength: " <<  t1.getLength() << std::endl << std::endl;

	Triangle t2;
	t2.setHeight(1.0f);
	t2.setLength(5.0f);
	std::cout << "Triangle2 Area: " << t2.getArea() << "\nheight: " <<  t2.getHeight() << "\nLength: " <<  t2.getLength() << std::endl << std::endl;

	Triangle t3(50.0f, 100.0f);
	std::cout << "Triangle3 Area: " << t3.getArea() << "\nheight: " <<  t3.getHeight() << "\nLength: " <<  t3.getLength() << std::endl << std::endl;

	Rectangle r1;
	r1.setLength(1.0f);
	r1.setWidth(3.5f);
	std::cout << "Rectangle Area: " << r1.getArea() << "\nlength: " << r1.getLength() << "\nwidth: " << r1.getWidth() << std::endl << std::endl;

	system("pause");
}