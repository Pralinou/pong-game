
class Paddle {

public:
	
	//Constructeur
	Paddle(float m_width, float m_height, float m_x, float m_y);


	/*Accesseurs*/
	float getm_x() const;
	float getm_y() const;
	float getm_width() const;
	float getm_height() const;
	float getm_speed() const;
   

protected:
	

private:

	//Position du paddle
	float m_x = 0;
	float m_y = 0;

	//Dimention du paddle
	float m_width = 10;
    float m_height = 60;

	//Vitesse du Paddle
	float m_speed = 6;
};

