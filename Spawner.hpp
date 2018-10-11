#ifndef SPAWNER_HPP
# define SPAWNER_HPP

# include <random>
# include "Enemy.hpp"
# include "LaserShark.hpp"
# include "structs.hpp"

class	Spawner {

	public:

		Spawner(void);
		Spawner(int difficulty);
		~Spawner(void);

		void	spawn(t_enemies **alist);

	private:

		time_t				start;
		std::minstd_rand	r;
		unsigned int		invSpawnRate;
		unsigned int		count;

		void	spawnBoss(t_enemies **alist);

		Spawner(Spawner const & ref);
		Spawner & operator=(Spawner const & ref);

};

#endif
