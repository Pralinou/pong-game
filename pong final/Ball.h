
class Ball {


public:

	//Constructeur
	Ball(float m_radius, float m_x, float m_y, float m_speed);
	Ball();

	/*Accesseurs*/
	float getm_x() const;
	float getm_y() const;
	float getm_radius() const;
	float getm_speed() const;
	
protected:


private:

	//Position de la balle
	float m_x = 316.5;
	float m_y = 236.5;

	//Taille de la balle
	float m_radius = 7;

	//Vitesse de la balle
	float m_speed = 2.5;

};

