// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_nyra_compile
#define lyrix_header_guard_nyra_compile
#include <string_view>

namespace Nyra
{
    auto Compile(const std::string_view name) noexcept -> void;
}

#endif
#endif