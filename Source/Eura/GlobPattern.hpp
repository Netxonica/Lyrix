// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_glob_pattern
#define lyrix_header_guard_eura_glob_pattern
#include "Eura/RelativePattern.hpp"

namespace Eura
{
    using GlobPattern = std::variant<Pattern, RelativePattern>;
}

#endif
#endif