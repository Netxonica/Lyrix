// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/NotebookDocument.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, NotebookDocument& notebook_document) noexcept ->
    void
    {
        notebook_document.uri = object.at("uri").get<URI>();
        notebook_document.notebookType = object.at("notebookType").get<std::string>();
        notebook_document.version = object.at("version").get<std::int32_t>();
        if(object.contains("metadata"))
            notebook_document.metadata = object.at("metadata");
        const nlohmann::json& cells = object.at("cells");
        for(const nlohmann::json& cell : cells)
            notebook_document.cells.emplace_back(cell.get<NotebookCell>());
    }

    auto to_json(nlohmann::json& object, const NotebookDocument& notebook_document) noexcept ->
    void
    {
        object["uri"] = notebook_document.uri;
        object["notebookType"] = notebook_document.notebookType;
        object["version"] = notebook_document.version;
        if(notebook_document.metadata.has_value())
            object["metadata"] = *notebook_document.metadata;
        nlohmann::json cells = nlohmann::json::array();
        for(const NotebookCell& cell : notebook_document.cells)
            cells.emplace_back(cell);
        object["cells"] = cells;
    }
}

#endif