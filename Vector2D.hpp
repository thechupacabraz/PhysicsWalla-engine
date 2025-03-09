#ifndef VECTOR2D
#define VECTOR2D

#include <iostream>
#include <math.h>
#include <string>
#include "Constants.hpp"


using namespace std;

class Vector2D {
private:
	float x, y;
public:
	//constructors  
	Vector2D() : x(0), y(0) {};
	Vector2D(float x_, float y_) : x(x_), y(y_) {};

	//operators  
	Vector2D operator / (float scalar) const {
		if (scalar == 0) return Vector2D(0, 0);
		return Vector2D(x / scalar, y / scalar);
	}
	Vector2D operator * (float scalar) const { return Vector2D(x * scalar, y * scalar); }
	Vector2D operator + (const Vector2D& v) const { return Vector2D(x + v.x, y + v.y); }
	Vector2D operator - (const Vector2D& v) const { return Vector2D(x - v.x, y - v.y); }
	Vector2D& operator /= (const float n) {
		if (n == 0) return *this;
		x /= n;
		y /= n;
		return *this;
	}
	Vector2D& operator *= (const float n) {
		if (n == 0) return *this;
		x *= n;
		y *= n;
		return *this;
	}
	Vector2D& operator += (const Vector2D& v) {
		x += v.getX();
		y += v.getY();
		return *this;
	}
	Vector2D& operator -= (const Vector2D& v) {
		x -= v.getX();
		y -= v.getY();
		return *this;
	}
	Vector2D& operator = (const float n) {
		x = n;
		y = n;
		return *this;
	}
	bool operator == (const Vector2D& v) const {
		return x == v.getX() && y == v.getY();
	}
	bool operator != (const Vector2D& v) const {
		return !(*this == v);
	}

	//getter,setter  
	float getX() const { return this->x; }
	float getY() const { return this->y; }
	Vector2D getVector() { return *this; }
	string getVectorString() { return to_string(getX()) + " x + " + to_string(getY()) + " y"; }

	void setX(float x_) { this->x = x_; }
	void setY(float y_) { this->y = y_; }
	void setVector(Vector2D theVector) { *this = theVector; }

	//VectorMath  
	float dotProduct(const Vector2D& v) const { return x * v.x + y * v.y; }
	float crossProduct(const Vector2D& v) const { return x * v.y - y * v.x; }
	float magnitude() const { return sqrt(x * x + y * y); }
	float magnitudeSquared() const { return x * x + y * y; }
	Vector2D& normalize() {
		float mag = magnitude();
		if (mag != 0.0) {
			x /= mag;
			y /= mag;
		}
		return *this;
	}
	Vector2D unitVector() const {
		Vector2D resVector = Vector2D(0, 0);
		float mag = magnitude();
		if (mag != 0.0) {
			resVector.x = x / mag;
			resVector.y = y / mag;
		}
		return resVector;
	}

	//vector Function  
	void scale(const float n) { *this *= n; }
	void rotate(const float angle, const char mode) {
		float theAngle;
		if (mode == 'r' || mode == 'R') theAngle = angle; 
		else if (mode == 'd' || mode == 'D') theAngle = angle * PI / 180.0; 
		else {
			cout << "Invalid angle format" << endl;
			return; 
		}
		float tempX = x;
		x = x * cos(theAngle) - y * sin(theAngle);
		y = tempX * sin(theAngle) + y * cos(theAngle);
	}

	//Misc  
	void displayVector() const { cout << x << " x + " << y << " y" << endl; }
	void clear() { x = y = 0; }
};

#endif //!VECTOR2D




