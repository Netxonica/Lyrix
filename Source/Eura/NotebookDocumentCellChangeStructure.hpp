// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_notebook_document_cell_change_structure
#define lyrix_header_guard_eura_notebook_document_cell_change_structure
#include "Eura/TextDocumentItem.hpp"
#include "Eura/TextDocumentIdentifier.hpp"
#include "Eura/NotebookCellArrayChange.hpp"

namespace Eura
{
    struct [[nodiscard]] NotebookDocumentCellChangeStructure final
    {
        NotebookCellArrayChange array;

        std::optional<std::vector<TextDocumentItem>> didOpen;

        std::optional<std::vector<TextDocumentIdentifier>> didClose;
    };

    auto from_json(const nlohmann::json& object, NotebookDocumentCellChangeStructure&
    notebook_document_cell_change_structure) noexcept -> void;

    auto to_json(nlohmann::json& object, const NotebookDocumentCellChangeStructure&
    notebook_document_cell_change_structure) noexcept -> void;
}

#endif
#endif