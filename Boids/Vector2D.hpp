#ifndef __Vector2D_HPP__
#define __Vector2D_HPP__

#include <iostream>
#include <math.h> 
#include <SFML/Graphics.hpp>

// a class for a 2 dimensional Vector, using floats
class Vector2D {
public:
	float x;
	float y;

public:
	// constructors
	Vector2D();
	Vector2D(float _x, float _y);

	// get the distance between two vectors
	float distance(Vector2D& v);
	// get the magnitude of a vector
	float magnitude();
	// normalize a vector
	void nomalize();
	// limit the vector to the value provided
	void limit(float val);

	// calculate the angle of the Vector
	float angle();

	// getters and setters for the vector
	float get_x();
	float get_y();
	void set_x(float val);
	void set_y(float val);
	void set(float _x, float _y);

	// unary minus
	Vector2D operator -();

	// variable assignment for floats
	void operator = (float val);
	// variable assignment for vectors
	void operator = (Vector2D v);

	// binary operators for floats
	Vector2D operator *(float val);

	// binary operators for vectors
	Vector2D operator -(const Vector2D& v);
	Vector2D operator +(const Vector2D& v);

	// augmented assignments for floats
	void addNum(const float val);
	void subNum(const float val);
	void mulNum(const float val);
	void divNum(const float val);

	// augmented assignments for vectors
	void operator +=(const Vector2D& v);
	void operator -=(const Vector2D& v);
	void operator *=(const Vector2D& v);
	void operator /=(const Vector2D& v);
};
#endif