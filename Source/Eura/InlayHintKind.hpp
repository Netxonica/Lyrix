// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_inlay_hint_kind
#define lyrix_header_guard_eura_inlay_hint_kind
#include <cstdint>

namespace Eura
{
    enum class [[nodiscard]] InlayHintKind : std::uint8_t
    {
        Type = 1u,
        Parameter = 2u
    };
}

#endif
#endif