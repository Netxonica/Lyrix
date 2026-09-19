// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/NotebookDocumentChangeEvent.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, NotebookDocumentChangeEvent&
    notebook_document_change_event) noexcept -> void
    {
        if(object.contains("metadata"))
            notebook_document_change_event.metadata = object.at("metadata");
        if(object.contains("cells"))
            notebook_document_change_event.cells = object.at("cells").get<
            NotebookDocumentCellChanges>();
    }

    auto to_json(nlohmann::json& object, const NotebookDocumentChangeEvent&
    notebook_document_change_event) noexcept -> void
    {
        if(notebook_document_change_event.metadata.has_value())
            object["metadata"] = *notebook_document_change_event.metadata;
        if(notebook_document_change_event.cells.has_value())
            object["cells"] = *notebook_document_change_event.cells;
    }
}

#endif