#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "AScrObj.hpp"
# include "Weapon.hpp"
# include "structs.hpp"

class	Enemy : public AScrObj {
	public:
		Enemy(int y, int x);
		Enemy(int y, int x, char repr, Weapon *weapon);
		Enemy(Enemy const & ref);
		Enemy & operator=(Enemy const & ref);
		virtual ~Enemy(void);

		virtual char	getRepr(void);
		void			setWeapon(std::string const & weaponType);
		bool			onScreen(void);
		virtual void	move(void);
		virtual void	display(void);
		virtual void	fire(t_bullets **alist);
		bool			checkVisibility(void) const;
		void			invisify(void);
	
	protected:
		char	repr;
		Weapon	*weapon;
		bool	isVisible;
		Enemy(void);
};

#endif
