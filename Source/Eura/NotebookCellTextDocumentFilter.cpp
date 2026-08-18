// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/NotebookCellTextDocumentFilter.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, NotebookCellTextDocumentFilter&
    notebook_cell_text_document_filter) noexcept -> void
    {
        const nlohmann::json& notebook = object.at("notebook");
        if(notebook.is_string())
            notebook_cell_text_document_filter.notebook = notebook.get<std::string>();
        else
            notebook_cell_text_document_filter.notebook = notebook.get<NotebookDocumentFilter>();
        if(object.contains("language"))
            notebook_cell_text_document_filter.language = object.at("language").get<std::string>();
    }

    auto to_json(nlohmann::json& object, const NotebookCellTextDocumentFilter&
    notebook_cell_text_document_filter) noexcept -> void
    {
        std::visit([&object](auto&& notebook)
        {
            object["notebook"] = notebook;
        }, notebook_cell_text_document_filter.notebook);
        if(notebook_cell_text_document_filter.language.has_value())
            object["language"] = *notebook_cell_text_document_filter.language;
    }
}

#endif