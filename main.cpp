
#include <ncurses.h>
#include <unistd.h>

#include "Game.hpp"
// #include "Character.hpp"
// #include "KeyboardEvent.hpp"
// #include "macros.hpp"

int		main(void)
{
	Game	game;

	game.init();
	game.play();
	//game.endScreen();
	return (0);
}
