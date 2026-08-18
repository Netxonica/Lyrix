// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_notebook_cell_text_document_filter
#define lyrix_header_guard_eura_notebook_cell_text_document_filter
#include "Eura/NotebookDocumentFilter.hpp"

namespace Eura
{
    struct [[nodiscard]] NotebookCellTextDocumentFilter final
    {
        std::variant<std::string, NotebookDocumentFilter> notebook;

        std::optional<std::string> language;
    };

    auto from_json(const nlohmann::json& object, NotebookCellTextDocumentFilter&
    notebook_cell_text_document_filter) noexcept -> void;

    auto to_json(nlohmann::json& object, const NotebookCellTextDocumentFilter&
    notebook_cell_text_document_filter) noexcept -> void;
}

#endif
#endif