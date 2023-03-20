#include "Vector2D.hpp"


// constructors

Vector2D::Vector2D() {
	x = 0;
	y = 0;
}

Vector2D::Vector2D(float _x, float _y) {
	x = _x;
	y = _y;
}

// calculate the distance between two vectors/points using pythagoras
float Vector2D::distance(Vector2D& v) {
	return sqrt((x - v.x) * (x - v.x) + (y - v.y) * (y - v.y));
}

// calculate the magnitude of the vector
float Vector2D::magnitude() {
	return sqrt(x * x + y * y);
}

// normalize a vector
void Vector2D::nomalize() {
	float size = magnitude();

	if (size > 0) {
		x /= size;
		y /= size;
	}
}

// limits the vector
void Vector2D::limit(float val) {
	float size = magnitude();
	if (size > val) {
		this->x = x / size;
		this->y = y / size;
	}
}

// calcualte angle of a vector, might be broken
float Vector2D::angle() {
	return atan(y / x) * 180 / 3.141592635f;
}

// getters

float Vector2D::get_x() {
	return x;
}

float Vector2D::get_y() {
	return y;
}

// setters

void Vector2D::set_x(float val) {
	this->x = val;
}

void Vector2D::set_y(float val) {
	this->y = val;
}

void Vector2D::set(float _x, float _y) {
	x = _x;
	y = _y;
}

// unary minus
Vector2D Vector2D::operator-() {
	return Vector2D(-x, -y);
}

// variable assignment for a float
void Vector2D::operator=(float val) {
	this->x = val;
	this->y = val;
}

// variable assignment for a vector
void Vector2D::operator=(Vector2D v) {
	this->x = v.x;
	this->y = v.y;
}

// binary operators for floats
Vector2D Vector2D::operator*(float val) {
	return Vector2D(x * val, y * val);
}

// binary operators for Vectors

Vector2D Vector2D::operator-(const Vector2D& v) {
	return Vector2D(this->x - v.x, this->y - v.y);
}

Vector2D Vector2D::operator+(const Vector2D& v) {
	return Vector2D(this->x + v.x, this->y + v.y);
}

// augmented assignment operators for floats

void Vector2D::addNum(const float val) {
	x += val;
	y += val;
}

void Vector2D::subNum(const float val) {
	x -= val;
	y -= val;
}

void Vector2D::mulNum(const float val) {
	x *= val;
	y *= val;
}

void Vector2D::divNum(const float val) {
	x /= val;
	y /= val;
}

// augmented assignment operators for Vectors

void Vector2D::operator+=(const Vector2D& v) {
	x += v.x;
	y += v.y;
}

void Vector2D::operator-=(const Vector2D& v) {
	x -= v.x;
	y -= v.y;
}

void Vector2D::operator*=(const Vector2D& v) {
	x *= v.x;
	y *= v.y;
}

void Vector2D::operator/=(const Vector2D& v) {
	x /= v.x;
	y /= v.y;
}