/* ************************************************************
 * Syntox
 * Copyright 2012-2013 Lionel Clément. All rights reserved.
 * Author: Lionel Clément
 * Labri
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 ************************************************************ */

#ifndef COLORS_H
#define COLORS_H

#include <string>

typedef enum {WHITE,
	      BLACK,
	      RED,
	      BLUE,
	      GREEN,
	      PINK,
	      YELLOW,
	      BROWN,
	      VIOLET,
	      GRAY,
	      ORANGE
} colors;

extern std::string colorToStr[];

#endif //COLORS_H
