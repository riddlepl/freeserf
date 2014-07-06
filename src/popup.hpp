/*
 * popup.h - Popup GUI component
 *
 * Copyright (C) 2013  Jon Lund Steffensen <jonlst@gmail.com>
 *
 * This file is part of freeserf.
 *
 * freeserf is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * freeserf is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with freeserf.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _POPUP_H
#define _POPUP_H

#include "gui.h"
#include "minimap.h"
#include "freeserf.h"


typedef struct {
	gui_container_t cont;
	struct interface *interface;
	minimap_t minimap;

	box_t box;
} popup_box_t;

void popup_box_init(popup_box_t *popup, struct interface *interface);


#endif /* !_POPUP_H */
