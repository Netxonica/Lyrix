// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_text_document_content_change_event
#define lyrix_header_guard_eura_text_document_content_change_event
#include "Eura/TextDocumentContentChangePartial.hpp"
#include "Eura/TextDocumentContentChangeWholeDocument.hpp"

namespace Eura
{
    using TextDocumentContentChangeEvent = std::variant<TextDocumentContentChangePartial,
    TextDocumentContentChangeWholeDocument>;
}

#endif
#endif