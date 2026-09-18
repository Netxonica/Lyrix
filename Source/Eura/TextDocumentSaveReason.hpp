// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_text_document_save_reason
#define lyrix_header_guard_eura_text_document_save_reason
#include <cstdint>

namespace Eura
{
    enum class [[nodiscard]] TextDocumentSaveReason : std::uint8_t
    {
        Manual = 1u,
        AfterDelay = 2u,
        FocusOut = 3u
    };
}

#endif
#endif