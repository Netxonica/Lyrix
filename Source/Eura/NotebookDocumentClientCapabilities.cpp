// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/NotebookDocumentClientCapabilities.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, NotebookDocumentClientCapabilities&
    notebook_document_client_capabilities) noexcept -> void
    {
        notebook_document_client_capabilities.synchronization = object.at("synchronization").get<
        NotebookDocumentSyncClientCapabilities>();
    }

    auto to_json(nlohmann::json& object, const NotebookDocumentClientCapabilities&
    notebook_document_client_capabilities) noexcept -> void
    {
        object["synchronization"] = notebook_document_client_capabilities.synchronization;
    }
}

#endif