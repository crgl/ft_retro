#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "Weapon.hpp"
# include "structs.hpp"

class	Character {

	public:

		Character(void);
		~Character(void);

		void	setX(int x);
		void	setY(int y);
		int		getX(void) const;
		int		getY(void) const;
		bool	hit(void);
		void	upgrade(std::string const & weaponType);
		void	attack(t_bullets **alist) const;
		void	display(void) const;
		bool	collision(t_enemies *tene, t_bullets *tbull);
		
	private:
		int			x;
		int			y;
		int			lives;
		Weapon		*weapon;

		Character(Character const & ref);
		Character & operator=(Character const & ref);

};

#endif
