// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_nyra_file
#define lyrix_header_guard_nyra_file
#include <string>
#include <optional>
#include <string_view>

namespace Nyra::File
{
    [[nodiscard]] auto Write(const std::string_view path, const std::string_view content) noexcept
    -> bool;

    [[nodiscard]] auto Exists(const std::string_view path) noexcept -> bool;

    [[nodiscard]] auto Read(const std::string_view path) noexcept -> std::optional<std::string>;
}

#endif
#endif