#include <ncurses.h>
#include "Bullet.hpp"
#include "macros.hpp"

Bullet::Bullet(void) : AScrObj(1, 1), repr('o') {
	this->vector[0] = 0;
	this->vector[1] = 1;
}

Bullet::Bullet(Bullet const & ref) : AScrObj(ref), repr(ref.repr) {
	this->vector[0] = ref.vector[0];
	this->vector[1] = ref.vector[1];
}

Bullet & Bullet::operator=(Bullet const & ref) {
	AScrObj::operator=(ref);
	this->repr = ref.repr;
	this->vector[0] = ref.vector[0];
	this->vector[1] = ref.vector[1];
	return *this;
}

Bullet::~Bullet(void) {}

char	Bullet::getRepr(void) const {
	return this->repr;
}

int	const*	Bullet::getVector(void) const {
	return this->vector;
}

void		Bullet::setVector(int vec[2]) {
	this->vector[0] = vec[0];
	this->vector[1] = vec[1];
}

void		Bullet::move(void)
{
	this->setY(this->getY() + this->vector[0]);
	this->setX(this->getX() + this->vector[1]);
}

void		Bullet::display(void) const
{
	mvprintw(y, x, BULLET_SPRITE1);
}

bool		Bullet::onScreen(void)
{
	if (x >= 0 && x <= WIN_WIDTH && y >= 0 && y <= WIN_HEIGHT)
		return (true);
	return (false);
}
