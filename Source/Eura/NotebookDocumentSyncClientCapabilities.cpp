// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/NotebookDocumentSyncClientCapabilities.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, NotebookDocumentSyncClientCapabilities&
    notebook_document_sync_client_capabilities) noexcept -> void
    {
        if(object.contains("dynamicRegistration"))
            notebook_document_sync_client_capabilities.dynamicRegistration = object.at(
            "dynamicRegistration").get<bool>();
        if(object.contains("executionSummarySupport"))
            notebook_document_sync_client_capabilities.executionSummarySupport = object.at(
            "executionSummarySupport").get<bool>();
    }

    auto to_json(nlohmann::json& object, const NotebookDocumentSyncClientCapabilities&
    notebook_document_sync_client_capabilities) noexcept -> void
    {
        if(notebook_document_sync_client_capabilities.dynamicRegistration.has_value())
            object["dynamicRegistration"] = *notebook_document_sync_client_capabilities.
            dynamicRegistration;
        if(notebook_document_sync_client_capabilities.executionSummarySupport.has_value())
            object["executionSummarySupport"] = *notebook_document_sync_client_capabilities.
            executionSummarySupport;
    }
}

#endif