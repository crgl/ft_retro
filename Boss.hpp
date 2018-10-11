#ifndef BOSS_HPP
# define BOSS_HPP

# include "Weapon.hpp"
# include "Enemy.hpp"
# include "structs.hpp"

class	Boss : public Enemy {
	public:
		Boss(int y, int x);
		Boss(int y, int x, char repr, Weapon *weapon);
		Boss(Boss const & ref);
		Boss & operator=(Boss const & ref);
		virtual ~Boss(void);

		void			display(void);
		virtual void	fire(t_bullets **alist);
		void			move(void);
	
	private:

		bool	movingDown;

		Boss(void);
};

#endif
