// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_notebook_document_sync_options
#define lyrix_header_guard_eura_notebook_document_sync_options
#include "Eura/NotebookDocumentFilterWithNotebook.hpp"

namespace Eura
{
    struct [[nodiscard]] NotebookDocumentSyncOptions final
    {
        std::vector<NotebookDocumentFilterWithNotebook> notebookSelector;

        std::optional<bool> save;
    };

    auto from_json(const nlohmann::json& object, NotebookDocumentSyncOptions&
    notebook_document_sync_options) noexcept -> void;

    auto to_json(nlohmann::json& object, const NotebookDocumentSyncOptions&
    notebook_document_sync_options) noexcept -> void;
}

#endif
#endif