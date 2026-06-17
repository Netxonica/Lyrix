// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_nyra_architecture
#define lyrix_header_guard_nyra_architecture
#include <cstdint>
#include <string_view>

namespace Nyra
{
    enum class [[nodiscard]] Architecture : std::uint8_t
    {
        Arm64 = 0u,
        Amd64 = 1u,
        Riscv64 = 2u
    };

    [[nodiscard]] auto Stringify(const Architecture architecture) noexcept -> std::string_view;
}

#endif
#endif