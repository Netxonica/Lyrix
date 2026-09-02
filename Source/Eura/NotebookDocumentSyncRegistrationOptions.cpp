// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/NotebookDocumentSyncRegistrationOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, NotebookDocumentSyncRegistrationOptions&
    notebook_document_sync_registration_options) noexcept -> void
    {
        from_json(object, static_cast<NotebookDocumentSyncOptions&>(
        notebook_document_sync_registration_options));
        from_json(object, static_cast<StaticRegistrationOptions&>(
        notebook_document_sync_registration_options));
    }

    auto to_json(nlohmann::json& object, const NotebookDocumentSyncRegistrationOptions&
    notebook_document_sync_registration_options) noexcept -> void
    {
        to_json(object, static_cast<const NotebookDocumentSyncOptions&>(
        notebook_document_sync_registration_options));
        to_json(object, static_cast<const StaticRegistrationOptions&>(
        notebook_document_sync_registration_options));
    }
}

#endif