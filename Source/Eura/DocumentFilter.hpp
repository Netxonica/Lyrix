// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_document_filter
#define lyrix_header_guard_eura_document_filter
#include "Eura/TextDocumentFilter.hpp"
#include "Eura/NotebookCellTextDocumentFilter.hpp"

namespace Eura
{
    using DocumentFilter = std::variant<TextDocumentFilter, NotebookCellTextDocumentFilter>;
}

#endif
#endif