// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DidSaveNotebookDocumentParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DidSaveNotebookDocumentParams&
    did_save_notebook_document_params) noexcept -> void
    {
        did_save_notebook_document_params.notebookDocument = object.at("notebookDocument").get<
        NotebookDocumentIdentifier>();
    }

    auto to_json(nlohmann::json& object, const DidSaveNotebookDocumentParams&
    did_save_notebook_document_params) noexcept -> void
    {
        object["notebookDocument"] = did_save_notebook_document_params.notebookDocument;
    }
}

#endif