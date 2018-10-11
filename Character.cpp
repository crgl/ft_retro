#include <ncurses.h>
#include "Character.hpp"
#include "macros.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"

Character::Character(void) : x(1), y(1), lives(4) {
	this->weapon = new Weapon;
}

Character::Character(Character const & ref) : x(ref.x), y(ref.y), lives(ref.lives) {
	this->weapon = new Weapon(*(ref.weapon));
}

Character &	Character::operator=(Character const & ref) {
	this->x = ref.x;
	this->y = ref.y;
	this->lives = ref.lives;
	delete this->weapon;
	this->weapon = new Weapon(*(ref.weapon));
	return *this;
}

Character::~Character(void) {
	delete this->weapon;
}

void	Character::setX(int x) {
	if (x < 0)
		this->x = 0;
	else if (x > WIN_WIDTH - CHAR_WIDTH)
		this->x = WIN_WIDTH - CHAR_WIDTH;
	else
		this->x = x;
}

void	Character::setY(int y) {
	if (y < 0)
		this->y = 0;
	else if (y > WIN_HEIGHT - CHAR_HEIGHT)
		this->y = WIN_HEIGHT - CHAR_HEIGHT;
	else
		this->y = y;
}

int		Character::getX(void) const {
	return this->x;
}

int		Character::getY(void) const {
	return this->y;
}

bool	Character::hit(void) {
	this->lives--;
	if (this->lives == 0)
		return (true);
	return (false);
}

void	Character::upgrade(std::string const & weaponType) {
	if (weaponType == this->weapon->getType())
		this->weapon->upgrade();
	else {
		delete this->weapon;
		this->weapon = new Weapon(weaponType);
	}
}

void	Character::attack(t_bullets **alist) const {
	this->weapon->fire(this->y + 1, this->x + CHAR_WIDTH, alist);
}

void	Character::display(void) const {
	mvprintw(y, x, PLAYER_SPRITE1);
	mvprintw(y + 1, x, PLAYER_SPRITE2);
	mvprintw(y + 2, x, PLAYER_SPRITE3);
}

bool	Character::collision(t_enemies *tene, t_bullets *tbull)
{
	while (tene != nullptr)
	{
		if (!tene->enemy->checkVisibility()) {
			tene = tene->next;
			continue ;
		}
		if (abs(tene->enemy->getX() - x) < CHAR_WIDTH &&
			abs(tene->enemy->getY() - y) < CHAR_HEIGHT)
		{
			tene->enemy->invisify();
			return (true);
		}
		tene = tene->next;
	}
	while (tbull != nullptr)
	{
		if (abs(tbull->bullet->getX() - x) < CHAR_WIDTH &&
			abs(tbull->bullet->getY() - y) < CHAR_HEIGHT)
			return (true);
		tbull = tbull->next;
	}
	return (false);
}
