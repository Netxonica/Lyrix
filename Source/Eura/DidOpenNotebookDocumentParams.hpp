// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_did_open_notebook_document_params
#define lyrix_header_guard_eura_did_open_notebook_document_params
#include "Eura/NotebookDocument.hpp"
#include "Eura/TextDocumentItem.hpp"

namespace Eura
{
    struct [[nodiscard]] DidOpenNotebookDocumentParams final
    {
        NotebookDocument notebookDocument;

        std::vector<TextDocumentItem> cellTextDocuments;
    };

    auto from_json(const nlohmann::json& object, DidOpenNotebookDocumentParams&
    did_open_notebook_document_params) noexcept -> void;

    auto to_json(nlohmann::json& object, const DidOpenNotebookDocumentParams&
    did_open_notebook_document_params) noexcept -> void;
}

#endif
#endif