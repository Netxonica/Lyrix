// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_notebook_document_cell_changes
#define lyrix_header_guard_eura_notebook_document_cell_changes
#include "Eura/NotebookDocumentCellContentChanges.hpp"
#include "Eura/NotebookDocumentCellChangeStructure.hpp"

namespace Eura
{
    struct [[nodiscard]] NotebookDocumentCellChanges final
    {
        std::optional<NotebookDocumentCellChangeStructure> structure;

        std::optional<std::vector<NotebookCell>> data;

        std::optional<std::vector<NotebookDocumentCellContentChanges>> textContent;
    };

    auto from_json(const nlohmann::json& object, NotebookDocumentCellChanges&
    notebook_document_cell_changes) noexcept -> void;

    auto to_json(nlohmann::json& object, const NotebookDocumentCellChanges&
    notebook_document_cell_changes) noexcept -> void;
}

#endif
#endif