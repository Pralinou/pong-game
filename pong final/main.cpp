#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include <cstdlib>

#include "Paddle.h"
#include "Ball.h"
#include "main.h"
#include "input.h"


//fenetre du jeu
RenderWindow window;
//gestion des bouttons
Input input;

//pour contenir le texte
Font font;


//Score
int scoreJ1 = 0;
int scoreJ2 = 0;


void SetText(Text& txt, String str)
{
	//txt.setFont(font); //police
	//txt.setString(str); //chaine de caractère
	//txt.setCharacterSize(26);
	//txt.setFillColor(Color::Red);
	//txt.setPosition((WIN_WIDHT / 2), ); //postion
}




int main()
{	//charger fenetre
	window.create(VideoMode(WIN_WIDHT, WIN_HEIGHT, 32), "JEU PONG", Style::Default);
	
	//charger police
	font.loadFromFile("C:/Users/Praly/Desktop/cours/pong/pong final/pong final - Copie/x64/Debug/police.ttf");
	Text txt("test", font, 50);
	txt.setFillColor(Color::White);
	txt.setPosition(50, 50);

	SetText(txt, std::to_string(scoreJ1) + " | " + std::to_string(scoreJ2));

	
	//sf::RenderWindow window;
	//window.create(sf::VideoMode(640, 480), "Pong");
	//Modification de la position de la fenetre ( x=L , y=H)
	window.setPosition(sf::Vector2i(150, 50));
	//Definition des images par secondes maximal 
	window.setFramerateLimit(30);

	//Creation du Paddle de gauche 
	Paddle lPaddle(10, 60, 40, 210);
	sf::RectangleShape leftPaddle(sf::Vector2f(lPaddle.getm_width(), lPaddle.getm_height()));
	leftPaddle.setPosition(sf::Vector2f(lPaddle.getm_x(), lPaddle.getm_y()));

	//Creation du Paddle de droite
	Paddle rPaddle(10, 60, 590, 210);
	sf::RectangleShape rightPaddle(sf::Vector2f(rPaddle.getm_width(), rPaddle.getm_height()));
	rightPaddle.setPosition(sf::Vector2f(rPaddle.getm_x(), rPaddle.getm_y()));

	
	Ball cball;
	sf::CircleShape ball(cball.getm_radius());
	ball.setPosition(sf::Vector2f(cball.getm_x(), cball.getm_y()));
	sf::Vector2f ballSpeed(cball.getm_speed(), cball.getm_speed());


	while (window.isOpen()) {

		sf::Event event;
		//Test des evenements 
		while (window.pollEvent(event)) {

			//Si on clique sur fermer
			if (event.type == sf::Event::Closed)
				//On ferme la fenetre
				window.close();
		}

		/* Gestion des deplacements clavier du paddle de gauche */
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
			leftPaddle.move(0, -lPaddle.getm_speed());
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			leftPaddle.move(0, lPaddle.getm_speed());
		}

		/* Gestion des deplacements clavier du paddle de droite */
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			rightPaddle.move(0, -rPaddle.getm_speed());
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			rightPaddle.move(0, rPaddle.getm_speed());
		}

		/*Initialisation de la direction de la balle au depart*/
		ball.move(-ballSpeed.x, ballSpeed.y * 2);

		/*Gestion de collision avec un mur*/
		if (ball.getPosition().y <= 0) {
			std::cout << "Balle collision Haut" << std::endl;
			ballSpeed.y = -ballSpeed.y;

		}
		else if (ball.getPosition().y >= 420) {
			std::cout << "Balle collision Bas" << std::endl;
			ballSpeed.y = -ballSpeed.y;
		}
		else if (ball.getPosition().x <= 20) {
			std::cout << "Joueur 2 a marqué" << std::endl;
			//ball.setPosition(sf::Vector2f(cball.getm_x(), cball.getm_y()));
			ballSpeed.x = -ballSpeed.x;

		}
		else if (ball.getPosition().x >= 620) {
			std::cout << "Joueur 1 a marque" << std::endl;
			//ball.setPosition(sf::Vector2f(cball.getm_x(), cball.getm_y()));
			ballSpeed.x = -ballSpeed.x;

		}

		/*Gestion de collision avec un paddle*/
		sf::FloatRect ballBox = ball.getGlobalBounds();
		sf::FloatRect leftBox = leftPaddle.getGlobalBounds();
		sf::FloatRect rightBox = rightPaddle.getGlobalBounds();

		if (leftBox.intersects(ballBox)) {
			ballSpeed.x = -ballSpeed.x;
		}
		else if (rightBox.intersects(ballBox)) {
			ballSpeed.x = -ballSpeed.x;
		}

		/*Gestion de collision paddle gauche & mur*/
		if (leftPaddle.getPosition().y <= 0) {
			std::cout << "Padlle gauche collision Haut " << std::endl;
			leftPaddle.setPosition(40, 0);
		}
		else if (leftPaddle.getPosition().y > 360) {
			std::cout << "Padlle gauche collision Bas " << std::endl;
			leftPaddle.setPosition(40, 350);
		}

		/*Gestion de collision paddle droite & mur*/
		if (rightPaddle.getPosition().y <= 0) {
			std::cout << "Padlle droite collision Haut " << std::endl;
			rightPaddle.setPosition(590, 0);
		}
		else if (rightPaddle.getPosition().y > 350) {
			std::cout << "Padlle droite collision Bas " << std::endl;
			rightPaddle.setPosition(590, 350);
		}

		window.clear();
		window.draw(leftPaddle);
		window.draw(rightPaddle);
		window.draw(ball);
		window.draw(txt);
		window.display();
	
	}
	return 0;


}

