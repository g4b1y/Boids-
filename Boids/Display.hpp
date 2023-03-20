#ifndef __DISPLAY_HPP__
#define __DISPLAY_HPP__

#include <SFML/Graphics.hpp>
#include <vector>

#include "Boid.hpp"
#include "Vector2D.hpp"

// declare Boid to avoid inlcude loops


class Display {
private:
	int width;
	int height;

	float seperationWeight;
	float alignmentWeight;
	float cohesionWeight;

	// window to render on the screen
	sf::RenderWindow window;

	// boxes to adjust the values
	sf::RectangleShape box_seperation;
	sf::RectangleShape box_alignment;
	sf::RectangleShape box_cohesion;

	sf::Text seperation_text;

public:
	// vector containing all the boids
	std::vector<Boid> boids;

	// constructor
	Display();
	Display(int quantity);

	void mainloop();
	void draw();
};
#endif