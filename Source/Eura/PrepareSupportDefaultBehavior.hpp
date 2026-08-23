// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_prepare_support_default_behavior
#define lyrix_header_guard_eura_prepare_support_default_behavior
#include <cstdint>

namespace Eura
{
    enum class [[nodiscard]] PrepareSupportDefaultBehavior : std::uint8_t
    {
        Identifier = 1u
    };
}

#endif
#endif