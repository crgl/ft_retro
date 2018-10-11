#include "MegaWeapon.hpp"

MegaWeapon::MegaWeapon(void) {
	int		j;
	int		tmp_vec[2];

	this->upgradeLvl = 4;
	this->type = "MEGA";
	this->toFire = new Bullet*[maxLvl];
	for (int i = 0; i < maxLvl; i++) {
		toFire[i] = new Bullet[5 * (i + 1)];
		for (j = 0; j < 5 * (i + 1); j++) {
			tmp_vec[0] = this->toFire[i][j].getVector()[0];
			tmp_vec[1] = -1 * this->toFire[i][j].getVector()[1];
			this->toFire[i][j].setVector(tmp_vec);
		}
	}
}

MegaWeapon::MegaWeapon(MegaWeapon const & ref) : Weapon(ref) {
	int		j;

	this->toFire = new Bullet*[maxLvl];
	for (int i = 0; i < maxLvl; i++) {
		this->toFire[i] = new Bullet[i + 1];
		for (j = 0; j < (i + 1); j++) {
			this->toFire[i][j] = Bullet(ref.toFire[i][j]);
		}
	}
}

MegaWeapon &	MegaWeapon::operator=(MegaWeapon const & ref) {
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

MegaWeapon::~MegaWeapon(void) {
	for (int i = 0; i < maxLvl; i++) {
		delete [] this->toFire[i];
	}
	delete this->toFire;
}

void	MegaWeapon::fire(int y, int x, t_bullets **alist) const {
	Bullet	*tmp;
	t_bullets	*to_add;
	int			bulletHeight;
	int			tmp_vec[2];

	if (alist == nullptr)
		return ;
	for (int i = 0; i < 5 * (this->upgradeLvl + 1); i++) {
		tmp = new Bullet(this->toFire[upgradeLvl][i]);
		bulletHeight = y;
		bulletHeight += i - (2 * i * (i % 2));
		tmp->setY(bulletHeight);
		tmp->setX(x);
		tmp_vec[0] = tmp->getVector()[0];
		tmp_vec[1] = tmp->getVector()[1];
		tmp_vec[0] += 2 * (i % 2) - 1;
		tmp_vec[1] -= i;
		tmp->setVector(tmp_vec);
		to_add = new t_bullets;
		to_add->bullet = tmp;
		if (*alist)
			to_add->next = *alist;
		else
			to_add->next = nullptr;
		*alist = to_add;
	}
	return ;
}
