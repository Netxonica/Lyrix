// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_insert_text_mode
#define lyrix_header_guard_eura_insert_text_mode
#include <cstdint>

namespace Eura
{
    enum class [[nodiscard]] InsertTextMode : std::uint8_t
    {
        AsIs = 1u,
        AdjustIndentation = 2u
    };
}

#endif
#endif