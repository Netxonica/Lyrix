// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/NotebookDocumentFilterWithNotebook.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, NotebookDocumentFilterWithNotebook&
    notebook_document_filter_with_notebook) noexcept -> void
    {
        if(object.contains("notebook"))
        {
            const nlohmann::json& notebook = object.at("notebook");
            if(notebook.is_string())
                notebook_document_filter_with_notebook.notebook = notebook.get<std::string>();
            else
                notebook_document_filter_with_notebook.notebook = notebook.get<
                NotebookDocumentFilter>();
        }
        if(object.contains("cells"))
        {
            notebook_document_filter_with_notebook.cells = std::vector<NotebookCellLanguage>{};
            const nlohmann::json& cells = object.at("cells");
            for(const nlohmann::json& cell : cells)
                notebook_document_filter_with_notebook.cells->emplace_back(cell.get<
                NotebookCellLanguage>());
        }
    }

    auto to_json(nlohmann::json& object, const NotebookDocumentFilterWithNotebook&
    notebook_document_filter_with_notebook) noexcept -> void
    {
        if(notebook_document_filter_with_notebook.notebook.has_value())
            std::visit([&object](auto&& notebook)
            {
                object["notebook"] = notebook;
            }, *notebook_document_filter_with_notebook.notebook);
        if(notebook_document_filter_with_notebook.cells.has_value())
        {
            nlohmann::json cells = nlohmann::json::array();
            for(const NotebookCellLanguage& cell : *notebook_document_filter_with_notebook.cells)
                cells.emplace_back(cell);
            object["cells"] = cells;
        }
    }
}

#endif