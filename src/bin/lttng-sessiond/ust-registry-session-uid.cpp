/*
 * Copyright (C) 2022 Jérémie Galarneau <jeremie.galarneau@efficios.com>
 *
 * SPDX-License-Identifier: GPL-2.0-only
 *
 */

#include "ust-registry.hpp"

namespace lst = lttng::sessiond::trace;

ust_registry_session_per_uid::ust_registry_session_per_uid(
		const struct lst::abi& in_abi,
		uint32_t major,
		uint32_t minor,
		const char *root_shm_path,
		const char *shm_path,
		uid_t euid,
		gid_t egid,
		uint64_t tracing_id,
		uid_t tracing_uid) :
	ust_registry_session{in_abi, major, minor, root_shm_path, shm_path, euid, egid, tracing_id},
	_tracing_uid{tracing_uid}
{
	lttng::pthread::lock_guard registry_lock(_lock);
	_generate_metadata();
}

lttng_buffer_type ust_registry_session_per_uid::get_buffering_scheme() const noexcept
{
	return LTTNG_BUFFER_PER_UID;
}

void ust_registry_session_per_uid::_visit_environment(lst::trace_class_visitor& visitor) const
{
	ust_registry_session::_visit_environment(visitor);
	visitor.visit(lst::environment_field<int64_t>("tracer_buffering_id", _tracing_uid));
}
