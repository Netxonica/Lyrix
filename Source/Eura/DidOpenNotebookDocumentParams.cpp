// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DidOpenNotebookDocumentParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DidOpenNotebookDocumentParams&
    did_open_notebook_document_params) noexcept -> void
    {
        did_open_notebook_document_params.notebookDocument = object.at("notebookDocument").get<
        NotebookDocument>();
        const nlohmann::json& cellTextDocuments = object.at("cellTextDocuments");
        for(const nlohmann::json& cellTextDocument : cellTextDocuments)
            did_open_notebook_document_params.cellTextDocuments.emplace_back(cellTextDocument.get<
            TextDocumentItem>());
    }

    auto to_json(nlohmann::json& object, const DidOpenNotebookDocumentParams&
    did_open_notebook_document_params) noexcept -> void
    {
        object["notebookDocument"] = did_open_notebook_document_params.notebookDocument;
        nlohmann::json cellTextDocuments = nlohmann::json::array();
        for(const TextDocumentItem& cellTextDocument : did_open_notebook_document_params.
        cellTextDocuments)
            cellTextDocuments.emplace_back(cellTextDocument);
        object["cellTextDocuments"] = cellTextDocuments;
    }
}

#endif