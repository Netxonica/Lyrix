// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/NotebookDocumentCellChangeStructure.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, NotebookDocumentCellChangeStructure&
    notebook_document_cell_change_structure) noexcept -> void
    {
        notebook_document_cell_change_structure.array = object.at("array").get<
        NotebookCellArrayChange>();
        if(object.contains("didOpen"))
        {
            notebook_document_cell_change_structure.didOpen = std::vector<TextDocumentItem>{};
            const nlohmann::json& didOpen = object.at("didOpen");
            for(const nlohmann::json& did : didOpen)
                notebook_document_cell_change_structure.didOpen->emplace_back(did.get<
                TextDocumentItem>());
        }
        if(object.contains("didClose"))
        {
            notebook_document_cell_change_structure.didClose = std::vector<TextDocumentIdentifier>{
            };
            const nlohmann::json& didClose = object.at("didClose");
            for(const nlohmann::json& did : didClose)
                notebook_document_cell_change_structure.didClose->emplace_back(did.get<
                TextDocumentIdentifier>());
        }
    }

    auto to_json(nlohmann::json& object, const NotebookDocumentCellChangeStructure&
    notebook_document_cell_change_structure) noexcept -> void
    {
        object["array"] = notebook_document_cell_change_structure.array;
        if(notebook_document_cell_change_structure.didOpen.has_value())
        {
            nlohmann::json didOpen = nlohmann::json::array();
            for(const TextDocumentItem& did : *notebook_document_cell_change_structure.didOpen)
                didOpen.emplace_back(did);
            object["didOpen"] = didOpen;
        }
        if(notebook_document_cell_change_structure.didClose.has_value())
        {
            nlohmann::json didClose = nlohmann::json::array();
            for(const TextDocumentIdentifier& did : *notebook_document_cell_change_structure.
            didClose)
                didClose.emplace_back(did);
            object["didClose"] = didClose;
        }
    }
}

#endif