// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_document_highlight_kind
#define lyrix_header_guard_eura_document_highlight_kind
#include <cstdint>

namespace Eura
{
    enum class [[nodiscard]] DocumentHighlightKind : std::uint8_t
    {
        Text = 1u,
        Read = 2u,
        Write = 3u
    };
}

#endif
#endif