/*
 * Copyright (C) 2017 Jérémie Galarneau <jeremie.galarneau@efficios.com>
 *
 * SPDX-License-Identifier: LGPL-2.1-only
 *
 */

#ifndef LTTNG_CONDITION_SESSION_CONSUMED_SIZE_INTERNAL_H
#define LTTNG_CONDITION_SESSION_CONSUMED_SIZE_INTERNAL_H

#include <lttng/condition/session-consumed-size.h>
#include <lttng/condition/condition-internal.h>
#include <lttng/condition/evaluation-internal.h>
#include <common/buffer-view.h>
#include <common/macros.h>

struct lttng_payload;
struct lttng_payload_view;

struct lttng_condition_session_consumed_size {
	struct lttng_condition parent;
	struct {
		bool set;
		uint64_t value;
	} consumed_threshold_bytes;
	char *session_name;
};

struct lttng_condition_session_consumed_size_comm {
	uint64_t consumed_threshold_bytes;
	/* Length includes the trailing \0. */
	uint32_t session_name_len;
	char session_name[];
} LTTNG_PACKED;

struct lttng_evaluation_session_consumed_size {
	struct lttng_evaluation parent;
	uint64_t session_consumed;
};

struct lttng_evaluation_session_consumed_size_comm {
	uint64_t session_consumed;
} LTTNG_PACKED;

LTTNG_HIDDEN
struct lttng_evaluation *lttng_evaluation_session_consumed_size_create(
		uint64_t consumed);

LTTNG_HIDDEN
ssize_t lttng_condition_session_consumed_size_create_from_payload(
		struct lttng_payload_view *view,
		struct lttng_condition **condition);

LTTNG_HIDDEN
ssize_t lttng_evaluation_session_consumed_size_create_from_payload(
		struct lttng_payload_view *view,
		struct lttng_evaluation **evaluation);

#endif /* LTTNG_CONDITION_SESSION_CONSUMED_SIZE_INTERNAL_H */
