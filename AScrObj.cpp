#include "AScrObj.hpp"

AScrObj::AScrObj(int y, int x) : y(y), x(x) {}

AScrObj::AScrObj(AScrObj const & ref) : y(ref.y), x(ref.x) {}

AScrObj &	AScrObj::operator=(AScrObj const & ref) {
	this->y = ref.y;
	this->x = ref.x;
	return *this;
}

AScrObj::~AScrObj(void) {}

void	AScrObj::setY(int y) {
	this->y = y;
}

void	AScrObj::setX(int x) {
	this->x = x;
}

int		AScrObj::getX(void) const {
	return this->x;
}

int		AScrObj::getY(void) const {
	return this->y;
}
