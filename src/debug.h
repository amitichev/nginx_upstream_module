
/*
 * Redistribution and use in source and binary forms, with or
 * without modification, are permitted provided that the following
 * conditions are met:
 *
 * 1. Redistributions of source code must retain the above
 *    copyright notice, this list of conditions and the
 *    following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials
 *    provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY AUTHORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
 * AUTHORS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * Copyright (C) 2015-2019 Tarantool AUTHORS:
 * please see AUTHORS file.
 */

#ifndef DEBUG_UTILS_H
#define DEBUG_UTILS_H 1

#include <ngx_config.h>
#include <ngx_core.h>

#if defined(MY_DEBUG)

# if (NGX_HAVE_VARIADIC_MACROS)
# define dd(...) do { \
        fprintf(stderr, "tnt *** "); \
        fprintf(stderr, __VA_ARGS__); \
        fprintf(stderr, " at %s line %d.\n", __FILE__, __LINE__); \
      } while(0)
# else

#include <stdarg.h>
#include <stdio.h>
#include <stdarg.h>

static inline void dd(const char* fmt, ...) { }

# endif

#else

# if (NGX_HAVE_VARIADIC_MACROS)
# define dd(...)
# else

#include <stdarg.h>

static inline void
dd(const char* fmt, ...) { }

# endif

#endif /* MY_DEBUG */

static inline const u_char*
get_str_safe(const u_char *str) {
  return (str ? str : (const u_char *) "NULL");
}

#endif
