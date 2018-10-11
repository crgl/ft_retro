/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   KeyboardEvent.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 13:15:07 by jochang           #+#    #+#             */
/*   Updated: 2018/10/07 18:22:43 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARDEVENT_HPP
#define KEYBOARDEVENT_HPP

#include <ncurses.h>
#include "Character.hpp"
#define SPEED 2

class	KeyboardEvent
{
public:
	/* Canonical Member Functions */
	KeyboardEvent(void);
	KeyboardEvent(const KeyboardEvent &cpy);
	~KeyboardEvent(void);
	KeyboardEvent&	operator = (const KeyboardEvent &old);

	void	MoveCharacter(WINDOW *win, Character *c, t_bullets **bullets);
};

#endif
