// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/NotebookDocumentSyncOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, NotebookDocumentSyncOptions&
    notebook_document_sync_options) noexcept -> void
    {
        const nlohmann::json& notebookSelector = object.at("notebookSelector");
        for(const nlohmann::json& notebook : notebookSelector)
            notebook_document_sync_options.notebookSelector.emplace_back(notebook.get<
            NotebookDocumentFilterWithNotebook>());
        if(object.contains("save"))
            notebook_document_sync_options.save = object.at("save").get<bool>();
    }

    auto to_json(nlohmann::json& object, const NotebookDocumentSyncOptions&
    notebook_document_sync_options) noexcept -> void
    {
        nlohmann::json notebookSelector = nlohmann::json::array();
        for(const NotebookDocumentFilterWithNotebook& notebook : notebook_document_sync_options.
        notebookSelector)
            notebookSelector.emplace_back(notebook);
        object["notebookSelector"] = notebookSelector;
        if(notebook_document_sync_options.save.has_value())
            object["save"] = *notebook_document_sync_options.save;
    }
}

#endif