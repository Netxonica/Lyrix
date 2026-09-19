// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DidChangeNotebookDocumentParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DidChangeNotebookDocumentParams&
    did_change_notebook_document_params) noexcept -> void
    {
        did_change_notebook_document_params.notebookDocument = object.at("notebookDocument").get<
        VersionedNotebookDocumentIdentifier>();
        did_change_notebook_document_params.change = object.at("change").get<
        NotebookDocumentChangeEvent>();
    }

    auto to_json(nlohmann::json& object, const DidChangeNotebookDocumentParams&
    did_change_notebook_document_params) noexcept -> void
    {
        object["notebookDocument"] = did_change_notebook_document_params.notebookDocument;
        object["change"] = did_change_notebook_document_params.change;
    }
}

#endif