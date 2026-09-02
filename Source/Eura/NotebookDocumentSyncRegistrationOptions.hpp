// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_notebook_document_sync_registration_options
#define lyrix_header_guard_eura_notebook_document_sync_registration_options
#include "Eura/StaticRegistrationOptions.hpp"
#include "Eura/NotebookDocumentSyncOptions.hpp"

namespace Eura
{
    struct [[nodiscard]] NotebookDocumentSyncRegistrationOptions final :
    NotebookDocumentSyncOptions, StaticRegistrationOptions{};

    auto from_json(const nlohmann::json& object, NotebookDocumentSyncRegistrationOptions&
    notebook_document_sync_registration_options) noexcept -> void;

    auto to_json(nlohmann::json& object, const NotebookDocumentSyncRegistrationOptions&
    notebook_document_sync_registration_options) noexcept -> void;
}

#endif
#endif