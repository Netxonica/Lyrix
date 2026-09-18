// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/NotebookCell.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, NotebookCell& notebook_cell) noexcept -> void
    {
        notebook_cell.kind = object.at("kind").get<NotebookCellKind>();
        notebook_cell.document = object.at("document").get<DocumentUri>();
        if(object.contains("metadata"))
            notebook_cell.metadata = object.at("metadata");
        if(object.contains("executionSummary"))
            notebook_cell.executionSummary = object.at("executionSummary").get<ExecutionSummary>();
    }

    auto to_json(nlohmann::json& object, const NotebookCell& notebook_cell) noexcept -> void
    {
        object["kind"] = notebook_cell.kind;
        object["document"] = notebook_cell.document;
        if(notebook_cell.metadata.has_value())
            object["metadata"] = *notebook_cell.metadata;
        if(notebook_cell.executionSummary.has_value())
            object["executionSummary"] = *notebook_cell.executionSummary;
    }
}

#endif