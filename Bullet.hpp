#ifndef BULLET_HPP
# define BULLET_HPP

# include "AScrObj.hpp"

class	Bullet : public AScrObj {

	public:

		Bullet(void);
		Bullet(Bullet const & ref);
		Bullet & operator=(Bullet const & ref);
		~Bullet(void);

		char		getRepr(void) const;
		int	const*	getVector(void) const;
		void		setVector(int vec[2]);
		void		move(void);
		void		display(void) const;
		bool		onScreen(void);
	private:

		char	repr;
		int		vector[2];

};

#endif
