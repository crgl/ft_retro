#ifndef STRUCTS_HPP
# define STRUCTS_HPP

class Bullet;
class Enemy;

typedef struct	s_bullets
{
	Bullet				*bullet;
	struct s_bullets	*next;
}				t_bullets;

typedef struct	s_enemies
{
	Enemy				*enemy;
	struct s_enemies	*next;
}				t_enemies;

#endif
