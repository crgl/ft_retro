#ifndef LASERSHARK_HPP
# define LASERSHARK_HPP

# include "Weapon.hpp"
# include "Enemy.hpp"
# include "structs.hpp"

class	LaserShark : public Enemy {
	public:
		LaserShark(int y, int x);
		LaserShark(int y, int x, char repr, Weapon *weapon);
		LaserShark(LaserShark const & ref);
		LaserShark & operator=(LaserShark const & ref);
		virtual ~LaserShark(void);

		void			display(void);
	
	private:

		LaserShark(void);
};

#endif
