// Copyright (c) 2012-2018, The CryptoNote developers, The Vuecash developers.
// Licensed under the GNU Lesser General Public License. See LICENSING.md for details.

#pragma once

// defines are for Windows resource compiler
#define VUECASH_VERSION_WINDOWS_COMMA 1, 18, 3, 10
#define VUECASH_VERSION_WINDOWS_STRING "1.0.0-beta-20180310"

#ifdef __cplusplus

namespace vuecash {
inline const char *app_version() { return VUECASH_VERSION_WINDOWS_STRING; }
}

#endif
