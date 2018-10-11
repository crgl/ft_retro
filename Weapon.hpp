#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

# include "Bullet.hpp"
# include "structs.hpp"

class	Weapon {

	public:

		Weapon(void);
		Weapon(bool isEnemy);
		Weapon(std::string const & type);
		Weapon(Weapon const & ref);
		Weapon & operator=(Weapon const & ref);
		virtual ~Weapon(void);

		virtual void		fire(int y, int x, t_bullets **alist) const;
		void				upgrade(void);
		std::string const &	getType(void) const;

	protected:

		int		getUpgradeLvl(void) const;
		Bullet				**toFire;
		int					upgradeLvl;
		std::string			type;
		static int const	maxLvl;

};

#endif
