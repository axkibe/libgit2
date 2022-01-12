/*
 * Copyright (C) the libgit2 contributors. All rights reserved.
 *
 * This file is part of libgit2, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included COPYING file.
 */
#ifndef INCLUDE_git_transport_h__
#define INCLUDE_git_transport_h__

#include "indexer.h"
#include "net.h"
#include "types.h"
#include "cert.h"
#include "credential.h"
#include "sys/stream.h"

/**
 * @file git2/transport.h
 * @brief Git transport interfaces and functions
 * @defgroup git_transport interfaces and functions
 * @ingroup Git
 * @{
 */
GIT_BEGIN_DECL

/**
 * Callback for messages received by the transport.
 *
 * Return a negative value to cancel the network operation.
 *
 * @param str The message from the transport
 * @param len The length of the message
 * @param payload Payload provided by the caller
 */
typedef int GIT_CALLBACK(git_transport_message_cb)(const char *str, int len, void *payload);

/** Signature of a function which creates a transport */
typedef int GIT_CALLBACK(git_transport_cb)(git_transport **out, git_remote *owner, void *param);

/**
 * Hook for ssh sessions.
 *
 * REQUEST: called to get new (or used) session
 * PREPARE: called before using a new session
 * RELEASE: called before closing/freeing a session
 **/
typedef enum{
	GIT_SSH_SESSION_HOOK_REQUEST = 1,
	GIT_SSH_SESSION_HOOK_PREPARE = 2,
	GIT_SSH_SESSION_HOOK_RELEASE = 3
} git_ssh_session_hook_state_t;

typedef int GIT_CALLBACK(git_ssh_session_hook)(git_ssh_session_hook_state_t state, const char *url, git_stream **io, LIBSSH2_SESSION **session);


/** @} */
GIT_END_DECL

#endif
