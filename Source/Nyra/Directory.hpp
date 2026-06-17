// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_nyra_directory
#define lyrix_header_guard_nyra_directory
#include <string_view>

namespace Nyra::Directory
{
    [[nodiscard]] auto Exists(const std::string_view path) noexcept -> bool;

    [[nodiscard]] auto Create(const std::string_view path) noexcept -> bool;
}

#endif
#endif