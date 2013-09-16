#ifndef HEALTH_RELAYD_H
#define HEALTH_RELAYD_H

/*
 * Copyright (C) 2012 - David Goulet <dgoulet@efficios.com>
 * Copyright (C) 2013 - Mathieu Desnoyers <mathieu.desnoyers@efficios.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License, version 2 only, as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 51
 * Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <lttng/health-internal.h>

enum health_type {
	HEALTH_RELAYD_TYPE_DISPATCHER		= 0,
	HEALTH_RELAYD_TYPE_WORKER		= 1,
	HEALTH_RELAYD_TYPE_LISTENER		= 2,

	NR_HEALTH_RELAYD_TYPES,
};

#endif /* HEALTH_RELAYD_H */
