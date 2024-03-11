#include <iostream>
#include <SFML/Graphics.hpp>
#include "input.h"
#include <SFML/Window/Joystick.hpp>


//fenetre de jeu 
const int WIN_WIDHT = 640;
const int WIN_HEIGHT = 420;

// Namespaces
using namespace sf;
using namespace std;

//gerez le texte
void SetText(Text& txt, String str);
void CheckBtn();

