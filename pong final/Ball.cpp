#include "Ball.h"


 //Constructeur
Ball::Ball(float radius, float x , float y, float speed) 
	: m_radius(radius), m_x(x), m_y(y), m_speed(speed)
{
}
Ball::Ball() = default;

 /*Accesseurs*/
float Ball::getm_x() const {

	return m_x;
}

float Ball::getm_y() const {

	return m_y;
}

float Ball::getm_radius() const {

	return m_radius;
}

float Ball::getm_speed() const {

	return m_speed;
}