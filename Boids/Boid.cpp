#include "Boid.hpp"


float wrap(float x, float m) {
    // wraps boids, which leave the screen to the other screen side
    float res = fmod(x, m);
    return res < 0 ? res + m : res;
}

void keep_in_bounds(Vector2D position, Vector2D velocity, float width, float height) {
    // attempt at making boids turn at the end of the screen instead of wrapping around

    const float margin = 200.f; // margin of where to begin turning around
    const float turn_factor = 10.f; // how much to turn around

    if (position.x < margin) {
        velocity.x += turn_factor;
    }
    if (position.x > width - margin) {
        velocity.x -= turn_factor;
    }
    if (position.y < margin) {
        velocity.y += turn_factor;
    }
    if (position.y < height - margin) {
        velocity.y -= turn_factor;
    }
}

Boid::Boid() {
    // constructor of a Boid with no arguments
    position = Vector2D(50.f, 50.f);
    shape.setPointCount(3); // lowering the resolution of the circle so much, that it becomes a triangle
    shape.setRadius(8.0f); // setting the readius of the circle
    shape.setFillColor(sf::Color(255, 0, 0)); // colering the 'circles' red
    shape.setPosition(position.x, position.y); // giving the CircleShape an position equal to the Boid position
}

Boid::Boid(float _x, float _y) {
    // constructor with arguments for the postion
    position = Vector2D(_x, _y);
    //shape.setPointCount(3); // lowering the resolution of the circle so much, that it becomes a triangle
    velocity = Vector2D(rand() % 50 - 25, rand() % 50 - 25); // randomizing the velocity of the Boid to make it more FUUUNNN!!!
    shape.setRadius(3.0f); // setting the readius of the circle
    shape.setFillColor(sf::Color(0, 255, 0)); // colering the 'circles' green
    shape.setPosition(position.x, position.y); // giving the CircleShape an position equal to the Boid position
}

Boid::Boid(float _x, float _y, sf::Color color) {
    // constructor with arguments for the postion
    position = Vector2D(_x, _y);
    //shape.setPointCount(3); // lowering the resolution of the circle so much, that it becomes a triangle
    velocity = Vector2D(rand() % 50 - 25, rand() % 50 - 25); // randomizing the velocity of the Boid to make it more FUUUNNN!!!
    shape.setRadius(3.0f); // setting the readius of the circle
    shape.setFillColor(color); // colering the 'circles' green
    shape.setPosition(position.x, position.y); // giving the CircleShape an position equal to the Boid position
}

void Boid::update_position(int width, int height) {
    // method for updating the postion of the boid

    // adding the velocity to the postion for movement and using the method wrap() to keep the Boids on screen
    this->position.x = wrap(this->position.x + this->velocity.x, static_cast<float>(width));
    this->position.y = wrap(this->position.y + this->velocity.y, static_cast<float>(height));

    // updating the position of the CircleShape
    shape.setPosition(sf::Vector2f(position.x, position.y));

    // trying to Rotate the Cricleshape according to the velocity, works around half of the time, other half looks just confusing
    shape.setRotation(velocity.angle() + 210);
}


void Boid::update_movement(std::vector<Boid>& boids, float seperationWeight, float alignmentWeight, float cohesionWeight) {
    // funciton to update the movement
    int count = 0;
    float viewrange = 100.f;

    Vector2D alignment(0.f, 0.f);
    Vector2D cohesion(0.f, 0.f);
    Vector2D seperation(0.f, 0.f);

    // iterating over all boids
    for (int i = 0; i < boids.size(); i++) {
        // calculating the distance to each boid
        float d = position.distance(boids[i].position);

        if (d > 0 && d < viewrange) { // filtering for within a viewrange and filtering the same boid as this
            // summing all the necessary data from the visible boids, to average them later out
            alignment += boids[i].velocity;
            cohesion += boids[i].position;
            seperation += boids[i].position - position;
            // incrementing count to keep track of the number of boids in the viewrange and to later calculate the average
            count++;
        }
    }

    if (count > 0) {
        // averaging the commulative velocity 
        alignment.divNum(static_cast<float>(count));
        // averaging the commulative position 
        cohesion.divNum(static_cast<float>(count));
        // averaging the commulative distance 
        seperation.divNum(static_cast<float>(count));

        // subracting the position to get the distance
        cohesion -= position;
        // negating the position, because seperation has to point away from the local flock of boids
        seperation = -seperation;

        // normalizing all three vectors
        alignment.nomalize();
        cohesion.nomalize();
        seperation.nomalize();

        // adding the vectors to velocity, adjust the floats for diffrent flocking behaviours
        velocity += alignment * alignmentWeight + cohesion * cohesionWeight + seperation * seperationWeight;

        // normalizing the speedvector
        velocity.nomalize();
        // and multiplying the vector to get a consistent velocity
        velocity.mulNum(5.f);
    }
}