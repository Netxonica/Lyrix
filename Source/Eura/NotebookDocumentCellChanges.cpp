// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/NotebookDocumentCellChanges.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, NotebookDocumentCellChanges&
    notebook_document_cell_changes) noexcept -> void
    {
        if(object.contains("structure"))
            notebook_document_cell_changes.structure = object.at("structure").get<
            NotebookDocumentCellChangeStructure>();
        if(object.contains("data"))
        {
            notebook_document_cell_changes.data = std::vector<NotebookCell>{};
            const nlohmann::json& data = object.at("data");
            for(const nlohmann::json& dat : data)
                notebook_document_cell_changes.data->emplace_back(dat.get<NotebookCell>());
        }
        if(object.contains("textContent"))
        {
            notebook_document_cell_changes.textContent = std::vector<NotebookDocumentCellContentChanges>{};
            const nlohmann::json& textContent = object.at("textContent");
            for(const nlohmann::json& text : textContent)
                notebook_document_cell_changes.textContent->emplace_back(text.get<
                NotebookDocumentCellContentChanges>());
        }
    }

    auto to_json(nlohmann::json& object, const NotebookDocumentCellChanges&
    notebook_document_cell_changes) noexcept -> void
    {
        if(notebook_document_cell_changes.structure.has_value())
            object["structure"] = *notebook_document_cell_changes.structure;
        if(notebook_document_cell_changes.data.has_value())
        {
            nlohmann::json data = nlohmann::json::array();
            for(const NotebookCell& dat : *notebook_document_cell_changes.data)
                data.emplace_back(dat);
            object["data"] = data;
        }
        if(notebook_document_cell_changes.textContent.has_value())
        {
            nlohmann::json textContent = nlohmann::json::array();
            for(const NotebookDocumentCellContentChanges& text : *notebook_document_cell_changes.
            textContent)
                textContent.emplace_back(text);
            object["textContent"] = textContent;
        }
    }
}

#endif