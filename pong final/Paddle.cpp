#include "Paddle.h"


//Constructeur
Paddle::Paddle(float width, float height, float x, float y)
	: m_width(width), m_height(height), m_x(x), m_y(y)
{
}

/*Accesseurs*/

float Paddle::getm_x() const {

	return m_x;
}

float Paddle::getm_y() const {

	return m_y;
}

float Paddle::getm_width() const {

	return m_width;
}

float Paddle::getm_height() const {

	return m_height;
}

float Paddle::getm_speed() const {

	return m_speed;
}