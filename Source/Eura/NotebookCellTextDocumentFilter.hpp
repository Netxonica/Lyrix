// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_notebook_cell_text_document_filter
#define lyrix_header_guard_eura_notebook_cell_text_document_filter
#include "Eura/NotebookDocumentFilter.hpp"

namespace Eura
{
    struct [[nodiscard]] NotebookCellTextDocumentFilter final
    {
        std::variant<Json::String, NotebookDocumentFilter> notebook;

        std::optional<Json::String> language;
    };

    auto Deserialize(const Json::Object& object, NotebookCellTextDocumentFilter&
    notebook_cell_text_document_filter) noexcept -> void;

    auto Serialize(Json::Object& object, const NotebookCellTextDocumentFilter&
    notebook_cell_text_document_filter) noexcept -> void;
}

#endif
#endif