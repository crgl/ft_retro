#include <ncurses.h>
#include "Game.hpp"

void	bulletCheck(t_bullets **bullets);
void	enemyCheck(t_enemies **enemies, t_bullets **bullets);

Game::Game(void) { }
Game::~Game(void)
{
	t_enemies	*tene;
	while (enemies)
	{
		tene = enemies;
		enemies = enemies->next;
		delete tene;
	}
	t_bullets	*tbull;
	while (bullets)
	{
		tbull = bullets;
		bullets = bullets->next;
		delete tbull;
	}
	endwin();
}

void	Game::init(void)
{
	initscr();
	noecho();
	curs_set(0);
	win = newwin(WIN_WIDTH, WIN_HEIGHT, 0, 0);
	nodelay(win, TRUE);
	keypad(win,TRUE);
	gameOver = false;
	enemies = nullptr;
	bullets = nullptr;
}

void	Game::play(void)
{
	t_enemies	*tene;
	
	while (!gameOver)
	{
		erase();
		keyboard.MoveCharacter(win, &character, &bullets);
		spawner.spawn(&enemies);
		bulletCheck(&bullets);
		enemyCheck(&enemies, &bullets);
		character.display();
		if (character.collision(enemies, bullets))
			gameOver = character.hit();
		refresh();
		usleep(30000);
	}
}
