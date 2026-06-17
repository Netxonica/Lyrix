// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_nyra_system
#define lyrix_header_guard_nyra_system
#include <cstdint>
#include <string_view>

namespace Nyra
{
    enum class [[nodiscard]] System : std::uint8_t
    {
        Darwin = 0u,
        Linux = 1u,
        Windows = 2u
    };

    [[nodiscard]] auto Stringify(const System system) noexcept -> std::string_view;
}

#endif
#endif