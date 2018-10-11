#ifndef GAME_HPP
# define GAME_HPP

# include <string>
# include <ncurses.h>
# include <unistd.h>
# include "Character.hpp"
# include "Spawner.hpp"
# include "KeyboardEvent.hpp"
# include "macros.hpp"

class	Game {

	public:

		Game(void);
		~Game(void);

		void	init(void);
		void	play(void);

		t_enemies	*enemies;
		t_bullets	*bullets;

	private:
		WINDOW			*win;
		KeyboardEvent	keyboard;
		bool			gameOver;

		Character		character;
		Spawner			spawner;
		/*
		WINDOW *	field;
		WINDOW *	timer;
		WINDOW *	stats;

		Character	buddy;
		Spawner		nest;

		Game(void);
		Game(Game const & ref);
		Game & operator=(Game const & ref);
		*/
};

#endif
