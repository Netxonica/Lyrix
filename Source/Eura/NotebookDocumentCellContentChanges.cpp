// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/NotebookDocumentCellContentChanges.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, NotebookDocumentCellContentChanges&
    notebook_document_cell_content_changes) noexcept -> void
    {
        notebook_document_cell_content_changes.document = object.at("document").get<
        VersionedTextDocumentIdentifier>();
        const nlohmann::json& changes = object.at("changes");
        for(const nlohmann::json& change : changes)
        {
            if(change.contains("range"))
                notebook_document_cell_content_changes.changes.emplace_back(change.get<
                TextDocumentContentChangePartial>());
            else
                notebook_document_cell_content_changes.changes.emplace_back(change.get<
                TextDocumentContentChangeWholeDocument>());
        }
    }

    auto to_json(nlohmann::json& object, const NotebookDocumentCellContentChanges&
    notebook_document_cell_content_changes) noexcept -> void
    {
        object["document"] = notebook_document_cell_content_changes.document;
        nlohmann::json changes = nlohmann::json::array();
        for(const TextDocumentContentChangeEvent& change : notebook_document_cell_content_changes.
        changes)
            std::visit([&changes](auto&& change)
            {
                changes.emplace_back(change);
            }, change);
        object["changes"] = changes;
    }
}

#endif