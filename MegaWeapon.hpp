#ifndef MEGAWEAPON_HPP
# define MEGAWEAPON_HPP

# include <string>

# include "Weapon.hpp"
# include "structs.hpp"

class	MegaWeapon : public Weapon {

	public:

		MegaWeapon(void);
		MegaWeapon(MegaWeapon const & ref);
		MegaWeapon & operator=(MegaWeapon const & ref);
		virtual ~MegaWeapon(void);

		void	fire(int y, int x, t_bullets **alist) const;

};

#endif
