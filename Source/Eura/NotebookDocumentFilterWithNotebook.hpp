// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_notebook_document_filter_with_notebook
#define lyrix_header_guard_eura_notebook_document_filter_with_notebook
#include "Eura/NotebookCellLanguage.hpp"
#include "Eura/NotebookDocumentFilter.hpp"

namespace Eura
{
    struct [[nodiscard]] NotebookDocumentFilterWithNotebook final
    {
        std::optional<std::variant<std::string, NotebookDocumentFilter>> notebook;

        std::optional<std::vector<NotebookCellLanguage>> cells;
    };

    auto from_json(const nlohmann::json& object, NotebookDocumentFilterWithNotebook&
    notebook_document_filter_with_notebook) noexcept -> void;

    auto to_json(nlohmann::json& object, const NotebookDocumentFilterWithNotebook&
    notebook_document_filter_with_notebook) noexcept -> void;
}

#endif
#endif