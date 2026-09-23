// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_apply_kind
#define lyrix_header_guard_eura_apply_kind
#include <cstdint>

namespace Eura
{
    enum class [[nodiscard]] ApplyKind : std::uint8_t
    {
        Replace = 1u,
        Merge = 2u
    };
}

#endif
#endif