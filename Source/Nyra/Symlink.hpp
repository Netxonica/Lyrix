// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_nyra_symlink
#define lyrix_header_guard_nyra_symlink
#include <string_view>

namespace Nyra::Symlink
{
    [[nodiscard]] auto Check(const std::string_view path) noexcept -> bool;
}

#endif
#endif