// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_notebook_document_cell_content_changes
#define lyrix_header_guard_eura_notebook_document_cell_content_changes
#include "Eura/TextDocumentContentChangeEvent.hpp"
#include "Eura/VersionedTextDocumentIdentifier.hpp"

namespace Eura
{
    struct [[nodiscard]] NotebookDocumentCellContentChanges final
    {
        VersionedTextDocumentIdentifier document;

        std::vector<TextDocumentContentChangeEvent> changes;
    };

    auto from_json(const nlohmann::json& object, NotebookDocumentCellContentChanges&
    notebook_document_cell_content_changes) noexcept -> void;

    auto to_json(nlohmann::json& object, const NotebookDocumentCellContentChanges&
    notebook_document_cell_content_changes) noexcept -> void;
}

#endif
#endif