// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_lumina_style
#define lyrix_header_guard_lumina_style
#include <string_view>

namespace Lumina::Style
{
    inline constexpr const std::string_view Normal = "\033[0m", Bold = "\033[1m", Italic =
    "\033[3m", Problem = "\033[31m", Path = "\033[32m", Data = "\033[34m", Numeric = "\033[35m",
    Token = "\033[36m";
}

#endif
#endif