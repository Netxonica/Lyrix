// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DocumentSymbolClientCapabilities.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DocumentSymbolClientCapabilities&
    document_symbol_client_capabilities) noexcept -> void
    {
        if(object.contains("dynamicRegistration"))
            document_symbol_client_capabilities.dynamicRegistration = object.at(
            "dynamicRegistration").get<bool>();
        if(object.contains("symbolKind"))
            document_symbol_client_capabilities.symbolKind = object.at("symbolKind").get<
            ClientSymbolKindOptions>();
        if(object.contains("hierarchicalDocumentSymbolSupport"))
            document_symbol_client_capabilities.hierarchicalDocumentSymbolSupport = object.at(
            "hierarchicalDocumentSymbolSupport").get<bool>();
        if(object.contains("tagSupport"))
            document_symbol_client_capabilities.tagSupport = object.at("tagSupport").get<
            ClientSymbolTagOptions>();
        if(object.contains("labelSupport"))
            document_symbol_client_capabilities.labelSupport = object.at("labelSupport").get<bool>(
            );
    }

    auto to_json(nlohmann::json& object, const DocumentSymbolClientCapabilities&
    document_symbol_client_capabilities) noexcept -> void
    {
        if(document_symbol_client_capabilities.dynamicRegistration.has_value())
            object["dynamicRegistration"] = *document_symbol_client_capabilities.
            dynamicRegistration;
        if(document_symbol_client_capabilities.symbolKind.has_value())
            object["symbolKind"] = *document_symbol_client_capabilities.symbolKind;
        if(document_symbol_client_capabilities.hierarchicalDocumentSymbolSupport.has_value())
            object["hierarchicalDocumentSymbolSupport"] = *document_symbol_client_capabilities.
            hierarchicalDocumentSymbolSupport;
        if(document_symbol_client_capabilities.tagSupport.has_value())
            object["tagSupport"] = *document_symbol_client_capabilities.tagSupport;
        if(document_symbol_client_capabilities.labelSupport.has_value())
            object["labelSupport"] = *document_symbol_client_capabilities.labelSupport;
    }
}

#endif