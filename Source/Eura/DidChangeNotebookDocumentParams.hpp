// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_did_change_notebook_document_params
#define lyrix_header_guard_eura_did_change_notebook_document_params
#include "Eura/NotebookDocumentChangeEvent.hpp"
#include "Eura/VersionedNotebookDocumentIdentifier.hpp"

namespace Eura
{
    struct [[nodiscard]] DidChangeNotebookDocumentParams final
    {
        VersionedNotebookDocumentIdentifier notebookDocument;

        NotebookDocumentChangeEvent change;
    };

    auto from_json(const nlohmann::json& object, DidChangeNotebookDocumentParams&
    did_change_notebook_document_params) noexcept -> void;

    auto to_json(nlohmann::json& object, const DidChangeNotebookDocumentParams&
    did_change_notebook_document_params) noexcept -> void;
}

#endif
#endif