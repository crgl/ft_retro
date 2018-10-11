#include "macros.hpp"
#include "Spawner.hpp"
#include "Boss.hpp"

Spawner::Spawner(void) : start(time(nullptr)), r(this->start), invSpawnRate(10), count(0) {}

Spawner::Spawner(int difficulty) : start(time(nullptr)), r(this->start), count(0) {
	this->invSpawnRate = 20 - difficulty;
	if (this->invSpawnRate < 2)
		this->invSpawnRate = 2;
}


Spawner::~Spawner(void) {}

void	Spawner::spawn(t_enemies **alist) {
	if (alist == nullptr)
		return ;
	if (count > 150) {
		this->spawnBoss(alist);
		return ;
	}
	if (count > 100) {
		count++;
		return ;
	}
	unsigned int	dur = time(nullptr) - this->start;
	if ((r() % this->invSpawnRate) || ((dur % 2) && (r() % 2)))
		return ;

	unsigned int	y = (r() % (WIN_HEIGHT - 5)) + 2;
	unsigned int	x = WIN_WIDTH - 30;
	Enemy			*tmp = nullptr;

	count++;
	if (r() % 3)
		tmp = new Enemy(y, x);
	else
		tmp = new LaserShark(y, x);
	if (tmp == nullptr)
		return ;
	if (*alist == nullptr) {
		*alist = new t_enemies;
		(*alist)->enemy = tmp;
		(*alist)->next = nullptr;
	}
	else {
		t_enemies		*to_add = new t_enemies;
		to_add->enemy = tmp;
		to_add->next = *alist;
		*alist = to_add;
	}
}

void	Spawner::spawnBoss(t_enemies ** alist) {
	unsigned int	y = WIN_HEIGHT / 2;
	unsigned int	x = WIN_WIDTH - 3;
	Enemy			*tmp;

	if (count != 151)
		return ;
	tmp = new Boss(y, x);
	if (*alist == nullptr) {
		*alist = new t_enemies;
		(*alist)->enemy = tmp;
		(*alist)->next = nullptr;
	}
	else {
		t_enemies		*to_add = new t_enemies;
		to_add->enemy = tmp;
		to_add->next = *alist;
		*alist = to_add;
	}
	count++;
}
