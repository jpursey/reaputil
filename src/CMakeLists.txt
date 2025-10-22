## Copyright (c) 2025 John Pursey
##
## Use of this source code is governed by an MIT-style License that can be found
## in the LICENSE file or at https://opensource.org/licenses/MIT.

set(reaplib_SOURCE
  clean.cc clean.h
)

set(reaplib_DEPS
  gb_file
  gb_parse
)

gb_add_library(reaplib)

set(reaputil_SOURCE
  reaputil.cc
)

set(reaputil_DEPS
  reaplib
)

gp_add_executable(reaputil)
