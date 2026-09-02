// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_text_document_sync_kind
#define lyrix_header_guard_eura_text_document_sync_kind
#include <cstdint>

namespace Eura
{
    enum class [[nodiscard]] TextDocumentSyncKind : std::uint8_t
    {
        None = 0u,
        Full = 1u,
        Incremental = 2u
    };
}

#endif
#endif