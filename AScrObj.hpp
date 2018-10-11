#ifndef ASCROBJ_HPP
# define ASCROBJ_HPP

# include <string>

class	AScrObj {

	public:

		AScrObj(int y, int x);
		virtual ~AScrObj(void);

		void	setX(int x);
		void	setY(int y);
		int		getX(void) const;
		int		getY(void) const;

	protected:

		int			y;
		int			x;

		AScrObj(AScrObj const & ref);
		AScrObj & operator=(AScrObj const & ref);
		AScrObj(void);


};

#endif
