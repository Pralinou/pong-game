#include "input.h"
#include "main.h"

//définis l'état des bouttons gérer par le jeu 
Input::Input()
{
	Button.left = Button.right = Button.up = Button.down= Button.escape = false;
}
//fonction qui sert à acceder à get button contenu dans private

Input::button Input::GetButton(void)const
{
	return Button;
}

//fonction qui permet de savoir si une entree en utilisé
void Input::InputHandler(Event event, RenderWindow& window)
{


	if (event.type == Event::Closed)
	{
		//fermer la fenêtre
		window.close();
	}



	if (event.type == Event::KeyPressed)
	{
		switch (event.key.code) //pour gerer toute les touches suceptible d'être utilisé
		{
		case Keyboard::Escape:
			Button.escape = true;
			break;
		case Keyboard::Left:
			Button.left = true;
			break;
		case Keyboard::Right:
			Button.right = true;
			break;
		case Keyboard::Up:
			Button.up = true;
			break;
		case Keyboard::Down:
			Button.down = true;
			break;
		default:
			break;
		}

		//Touche relachée la même sauf que l'état des bouttons passe à false 
		if (event.type == Event::KeyReleased)
		{
			switch (event.key.code)
				switch (event.key.code)
				{
				case Keyboard::Escape:
					Button.escape = false;
					break;
				case Keyboard::Left:
					Button.left = false;
					break;
				case Keyboard::Right:
					Button.right = false;
					break;
				case Keyboard::Up:
					Button.up = false;
					break;
				case Keyboard::Down:
					Button.down = false;
					break;
				default:
					break;
				}

		}

	}
}