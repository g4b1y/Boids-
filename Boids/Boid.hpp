#ifndef __BOID_HPP__
#define __BOID_HPP__

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

#include "Vector2D.hpp"

// deklare Vecor2D to avoid an include loop

class Boid {
private:
	// velocity and position attributes
	Vector2D velocity;
	Vector2D position;

public:
	sf::CircleShape shape;
	// the CicleShape can be drawn on the window
	// 
	// constructors
	Boid();
	Boid(float _x, float _y);
	Boid(float _x, float _y, sf::Color color);

	// update_movement movement
	void update_movement(std::vector<Boid>& boids, float seperationWeight, float alignmentWeight, float cohesionWeight);
	// update_position
	void update_position(int width, int height);
};
#endif