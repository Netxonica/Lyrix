// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DidCloseNotebookDocumentParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DidCloseNotebookDocumentParams&
    did_close_notebook_document_params) noexcept -> void
    {
        did_close_notebook_document_params.notebookDocument = object.at("notebookDocument").get<
        NotebookDocumentIdentifier>();
        const nlohmann::json& cellTextDocuments = object.at("cellTextDocuments");
        for(const nlohmann::json& cellTextDocument : cellTextDocuments)
            did_close_notebook_document_params.cellTextDocuments.emplace_back(cellTextDocument.get<
            TextDocumentIdentifier>());
    }

    auto to_json(nlohmann::json& object, const DidCloseNotebookDocumentParams&
    did_close_notebook_document_params) noexcept -> void
    {
        object["notebookDocument"] = did_close_notebook_document_params.notebookDocument;
        nlohmann::json cellTextDocuments = nlohmann::json::array();
        for(const TextDocumentIdentifier& cellTextDocument : did_close_notebook_document_params.
        cellTextDocuments)
            cellTextDocuments.emplace_back(cellTextDocument);
        object["cellTextDocuments"] = cellTextDocuments;
    }
}

#endif