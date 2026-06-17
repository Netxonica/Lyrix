// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_array
#define lyrix_header_guard_eura_array
#include <vector>

namespace Eura::Json
{
    struct [[nodiscard]] Any;

    using Array = std::vector<Any>;
}

#endif
#endif