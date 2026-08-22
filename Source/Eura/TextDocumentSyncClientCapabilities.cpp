// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/TextDocumentSyncClientCapabilities.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, TextDocumentSyncClientCapabilities&
    text_document_sync_client_capabilities) noexcept -> void
    {
        if(object.contains("dynamicRegistration"))
            text_document_sync_client_capabilities.dynamicRegistration = object.at(
            "dynamicRegistration").get<bool>();
        if(object.contains("willSave"))
            text_document_sync_client_capabilities.willSave = object.at("willSave").get<bool>();
        if(object.contains("willSaveWaitUntil"))
            text_document_sync_client_capabilities.willSaveWaitUntil = object.at(
            "willSaveWaitUntil").get<bool>();
        if(object.contains("didSave"))
            text_document_sync_client_capabilities.didSave = object.at("didSave").get<bool>();
    }

    auto to_json(nlohmann::json& object, const TextDocumentSyncClientCapabilities&
    text_document_sync_client_capabilities) noexcept -> void
    {
        if(text_document_sync_client_capabilities.dynamicRegistration.has_value())
            object["dynamicRegistration"] = *text_document_sync_client_capabilities.
            dynamicRegistration;
        if(text_document_sync_client_capabilities.willSave.has_value())
            object["willSave"] = *text_document_sync_client_capabilities.willSave;
        if(text_document_sync_client_capabilities.willSaveWaitUntil.has_value())
            object["willSaveWaitUntil"] = *text_document_sync_client_capabilities.willSaveWaitUntil
            ;
        if(text_document_sync_client_capabilities.didSave.has_value())
            object["didSave"] = *text_document_sync_client_capabilities.didSave;
    }
}

#endif