#ifndef INPUT_H
#define INPUT_H
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Input
{
	struct button { bool left, right, up, down, escape; };


public:
	Input();
	button GetButton(void)const; //retourne l'état de un boutton
	void InputHandler(Event event, RenderWindow& window);



private:
	button Button;
};

#endif // !INPUT_H
