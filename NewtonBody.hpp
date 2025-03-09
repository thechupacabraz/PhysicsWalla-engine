#include<iostream>
#include "Vector2D.hpp"
using namespace std;

class NewtonBody {
private:
	Vector2D x, vel, acc, force;
	float mass;

public:
	//constructors
	NewtonBody() : x(0,0), vel(0,0), acc(0, 0) , mass(1), force(0,0) {}
	NewtonBody(Vector2D pos, Vector2D u, Vector2D a, float m) : x(pos), vel(u), acc(a), mass(m) {
		if (m <= 0) throw invalid_argument("Mass can not be <= 0");
		force = acc * mass;
	};

	//Getter Setter
	Vector2D getPos() const { return this->x; }
	Vector2D getVel() const { return this->vel; }
	Vector2D getAcceleration() const { return this->acc; }
	float getMass() const { return this->mass; }
	Vector2D getForce() const { return this->force; }
	Vector2D getMomentum() const { return vel * mass; }
	float getKineticEnergy() const { return vel.magnitudeSquared() * mass * 0.5f; }
	float getPotentialEnergy() const { return SMALL_G * mass * x.getY(); }

	void setVel(Vector2D u) { this->vel = u; }
	void setAcceleration(Vector2D a) { this->acc = a; }
	void setMass(float m) { 
		if (m <= 0) throw invalid_argument("Mass can not be <= 0");
		mass = m;
	}
	void setPos(Vector2D pos) { this->x = pos; }

	//Manage Forces
	void applyForce(Vector2D f) { force += f; }
	void clearForces() { force = Vector2D(0, 0); }


	void applyImpulse(Vector2D impulse) { vel += impulse / mass; }

	void update(float dt) {
		acc = force / mass;
		vel += acc * dt;
		x += vel * dt + acc * (0.5f * dt * dt);
		clearForces();
	}

	void displayAll() {
		cout << "mass : " << mass << endl;
		cout << "Velocity: " << vel.getVectorString() << endl;
		cout << "Acceleration: " << acc.getVectorString() << endl;
		cout << "Position: " << x.getVectorString() << endl;
		cout << "Momentum: " << getMomentum().getVectorString() << endl;
		cout << "Force: " << force.getVectorString() << endl;
		cout << "Kinetic Energy: " << getKineticEnergy() << endl;
		cout << "Potential Energy: " << getPotentialEnergy() << endl;
	}

};