// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_insert_text_format
#define lyrix_header_guard_eura_insert_text_format
#include <cstdint>

namespace Eura
{
    enum class [[nodiscard]] InsertTextFormat : std::uint8_t
    {
        PlainText = 1u,
        Snippet = 2u
    };
}

#endif
#endif