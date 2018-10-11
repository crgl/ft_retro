#include <ncurses.h>
#include "Enemy.hpp"
#include "macros.hpp"

Enemy::Enemy(void) : AScrObj(1, 1), repr('*'), weapon(nullptr), isVisible(true) {}

Enemy::Enemy(int y, int x) : AScrObj(y, x), repr('*'), weapon(nullptr), isVisible(true) {}

Enemy::Enemy(int y, int x, char repr, Weapon * weapon) : AScrObj(y, x), repr(repr), weapon(weapon) {}

Enemy::Enemy(Enemy const & ref) : AScrObj(ref), repr(ref.repr), weapon(new Weapon(*(ref.weapon))) {}

Enemy &	Enemy::operator=(Enemy const & ref) {
	AScrObj::operator=(ref);
	this->repr = ref.repr;
	if (this->weapon != nullptr)
		delete this->weapon;
	this->weapon = new Weapon(*(this->weapon));
	return *this;
}

Enemy::~Enemy(void) {
	if (this->weapon != nullptr)
		delete this->weapon;
}

char	Enemy::getRepr(void)
{
	return this->repr;
}

void	Enemy::move(void)
{
	//implement pattern here
	this->x -= ENEMY_SPEED;
}

void	Enemy::display(void)
{
	if (!this->checkVisibility())
		return ;
	mvprintw(y, x, ENEMY_SPRITE1);
	mvprintw(y + 1, x, ENEMY_SPRITE2);
	mvprintw(y + 2, x, ENEMY_SPRITE3);
	mvprintw(y + 3, x, ENEMY_SPRITE4);
	mvprintw(y + 4, x, ENEMY_SPRITE5);
}

bool	Enemy::onScreen(void)
{
	if (this->x >= 0 && this->x < WIN_WIDTH && this->y >= 0 && this->y < WIN_HEIGHT)
		return (true);
	return (false);
}
void	Enemy::fire(t_bullets **alist) {
	if (this->weapon != nullptr && (time(nullptr) % 2) && this->checkVisibility())
		this->weapon->fire(this->getY() + 2, this->getX() - 15, alist);
}

bool	Enemy::checkVisibility(void) const {
	return this->isVisible;
}

void	Enemy::invisify(void) {
	this->isVisible = false;
}
