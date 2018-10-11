/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   KeyboardEvent.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 13:15:05 by jochang           #+#    #+#             */
/*   Updated: 2018/10/07 19:01:11 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "KeyboardEvent.hpp"

/* Canonical Member Functions */
KeyboardEvent::KeyboardEvent(void) { }
KeyboardEvent::~KeyboardEvent(void) { }

void	KeyboardEvent::MoveCharacter(WINDOW *win, Character *c, t_bullets **bullets)
{
	switch((wgetch(win)))
	{
		case KEY_UP:
			c->setY(c->getY() - SPEED);
			break;
		case KEY_DOWN:
			c->setY(c->getY() + SPEED);
			break;
		case KEY_LEFT:
			c->setX(c->getX() - SPEED);
			break;
		case KEY_RIGHT:
			c->setX(c->getX() + SPEED);
			break;
		case ' ':
			c->attack(bullets);
			break;
		case 27:
			exit(0);
		default:
			break;
	}
}
