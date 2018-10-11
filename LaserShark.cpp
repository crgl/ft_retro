#include <ncurses.h>
#include "LaserShark.hpp"
#include "macros.hpp"

LaserShark::LaserShark(void) : Enemy() {
	this->repr = '=';
	this->weapon = new Weapon(1);
}

LaserShark::LaserShark(int y, int x) : Enemy(y, x) {
	this->repr = '=';
	this->weapon = new Weapon(1);
}

LaserShark::LaserShark(int y, int x, char repr, Weapon * weapon) : Enemy(y, x, repr, weapon) {}

LaserShark::LaserShark(LaserShark const & ref) : Enemy(ref) {}

LaserShark &	LaserShark::operator=(LaserShark const & ref) {
	Enemy::operator=(ref);
	return *this;
}

LaserShark::~LaserShark(void) {}

void	LaserShark::display(void)
{
	if (!this->checkVisibility())
		return ;
	mvprintw(y, x, SHARK_SPRITE_WKM1);
	mvprintw(y + 1, x, SHARK_SPRITE_WKM2);
	mvprintw(y + 2, x, SHARK_SPRITE_WKM3);
	mvprintw(y + 3, x, SHARK_SPRITE_WKM4);
}
