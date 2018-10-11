#include <ncurses.h>
#include "Boss.hpp"
#include "MegaWeapon.hpp"
#include "macros.hpp"

Boss::Boss(void) : Enemy(), movingDown(true) {
	this->repr = '=';
	this->weapon = new Weapon(1);
}

Boss::Boss(int y, int x) : Enemy(y, x), movingDown(true) {
	this->repr = '=';
	this->weapon = new MegaWeapon;
}

Boss::Boss(int y, int x, char repr, Weapon * weapon) : Enemy(y, x, repr, weapon), movingDown(true) {}

Boss::Boss(Boss const & ref) : Enemy(ref), movingDown(ref.movingDown) {}

Boss &	Boss::operator=(Boss const & ref) {
	Enemy::operator=(ref);
	this->movingDown = ref.movingDown;
	return *this;
}

Boss::~Boss(void) {
	if (this->weapon != nullptr)
		delete this->weapon;
}

void	Boss::display(void)
{
	if (!this->checkVisibility())
		return ;
	mvprintw(y, x, BOSS_SPRITE_1);
	mvprintw(y + 1, x, BOSS_SPRITE_2);
	mvprintw(y + 2, x, BOSS_SPRITE_3);
	mvprintw(y + 3, x, BOSS_SPRITE_4);
	mvprintw(y + 4, x, BOSS_SPRITE_5);
	mvprintw(y + 5, x, BOSS_SPRITE_6);
	mvprintw(y + 6, x, BOSS_SPRITE_7);
	mvprintw(y + 7, x, BOSS_SPRITE_8);
	mvprintw(y + 8, x, BOSS_SPRITE_9);
	mvprintw(y + 9, x, BOSS_SPRITE_10);
	mvprintw(y + 10, x, BOSS_SPRITE_11);
	mvprintw(y + 11, x, BOSS_SPRITE_12);
	mvprintw(y + 12, x, BOSS_SPRITE_13);
	mvprintw(y + 13, x, BOSS_SPRITE_14);
	mvprintw(y + 14, x, BOSS_SPRITE_15);
	mvprintw(y + 15, x, BOSS_SPRITE_16);
	mvprintw(y + 16, x, BOSS_SPRITE_17);
}

void	Boss::move(void)
{
	//implement pattern here
	if (this->movingDown)
		this->y += ENEMY_SPEED;
	else
		this->y -= ENEMY_SPEED;
	if (this->y < 5)
		this->movingDown = true;
	if (this->y > WIN_HEIGHT - 20)
		this->movingDown = false;
}

void	Boss::fire(t_bullets **alist) {
	if (this->weapon != nullptr && (time(nullptr) % 2) && this->checkVisibility())
		this->weapon->fire(this->getY(), this->getX(), alist);
}
