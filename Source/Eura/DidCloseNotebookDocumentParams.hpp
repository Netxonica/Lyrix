// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_did_close_notebook_document_params
#define lyrix_header_guard_eura_did_close_notebook_document_params
#include "Eura/TextDocumentIdentifier.hpp"
#include "Eura/NotebookDocumentIdentifier.hpp"

namespace Eura
{
    struct [[nodiscard]] DidCloseNotebookDocumentParams final
    {
        NotebookDocumentIdentifier notebookDocument;

        std::vector<TextDocumentIdentifier> cellTextDocuments;
    };

    auto from_json(const nlohmann::json& object, DidCloseNotebookDocumentParams&
    did_close_notebook_document_params) noexcept -> void;

    auto to_json(nlohmann::json& object, const DidCloseNotebookDocumentParams&
    did_close_notebook_document_params) noexcept -> void;
}

#endif
#endif