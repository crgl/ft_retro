#include "Weapon.hpp"

int	const	Weapon::maxLvl = 5;

Weapon::Weapon(void) : upgradeLvl(0), type("basic") {
	this->toFire = new Bullet*[maxLvl];
	for (int i = 0; i < maxLvl; i++) {
		toFire[i] = new Bullet[i + 1];
	}
}

Weapon::Weapon(bool isEnemy) : upgradeLvl(0), type("basic") {
	int		j;
	int		tmp_vec[2];

	this->toFire = new Bullet*[maxLvl];
	for (int i = 0; i < maxLvl; i++) {
		toFire[i] = new Bullet[i + 1];
		if (isEnemy) {
			for (j = 0; j < (i + 1); j++) {
				tmp_vec[0] = this->toFire[i][j].getVector()[0];
				tmp_vec[1] = -3 * this->toFire[i][j].getVector()[1];
				this->toFire[i][j].setVector(tmp_vec);
			}
		}
	}
}

Weapon::Weapon(std::string const & type) : upgradeLvl(0), type(type) {
	this->toFire = new Bullet*[maxLvl];
	for (int i = 0; i < maxLvl; i++) {
		toFire[i] = new Bullet[i + 1];
	}
}

Weapon::Weapon(Weapon const & ref) : upgradeLvl(ref.upgradeLvl), type(ref.type) {
	int		j;

	this->toFire = new Bullet*[maxLvl];
	for (int i = 0; i < maxLvl; i++) {
		this->toFire[i] = new Bullet[i + 1];
		for (j = 0; j < (i + 1); j++) {
			this->toFire[i][j] = Bullet(ref.toFire[i][j]);
		}
	}
}

Weapon &	Weapon::operator=(Weapon const & ref) {
	int		i;
	int		j;

	this->type = ref.type;
	this->upgradeLvl = ref.upgradeLvl;
	for (i = 0; i < maxLvl; i++) {
		delete [] this->toFire[i];
	}
	delete this->toFire;
	this->toFire = new Bullet*[maxLvl];
	for (i = 0; i < maxLvl; i++) {
		this->toFire[i] = new Bullet[i + 1];
		for (j = 0; j < (i + 1); j++) {
			this->toFire[i][j] = Bullet(ref.toFire[i][j]);
		}
	}
	return *this;
}

Weapon::~Weapon(void) {
	for (int i = 0; i < maxLvl; i++) {
		delete [] this->toFire[i];
	}
	delete this->toFire;
}

void	Weapon::fire(int y, int x, t_bullets **alist) const {
	Bullet	*tmp;
	t_bullets	*to_add;

	if (alist == nullptr)
		return ;
	for (int i = 0; i < this->upgradeLvl + 1; i++) {
		tmp = new Bullet(this->toFire[upgradeLvl][i]);
		tmp->setY(y);
		tmp->setX(x);
		to_add = new t_bullets;
		to_add->bullet = tmp;
		to_add->next = *alist;
		*alist = to_add;
	}
	return ;
}

void	Weapon::upgrade(void) {
	if (this->upgradeLvl < maxLvl - 1)
		this->upgradeLvl++;
}

std::string const &	Weapon::getType(void) const {
	return this->type;
}
