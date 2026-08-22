// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/WorkspaceSymbolClientCapabilities.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, WorkspaceSymbolClientCapabilities&
    workspace_symbol_client_capabilities) noexcept -> void
    {
        if(object.contains("dynamicRegistration"))
            workspace_symbol_client_capabilities.dynamicRegistration = object.at(
            "dynamicRegistration").get<bool>();
        if(object.contains("symbolKind"))
            workspace_symbol_client_capabilities.symbolKind = object.at("symbolKind").get<
            ClientSymbolKindOptions>();
        if(object.contains("tagSupport"))
            workspace_symbol_client_capabilities.tagSupport = object.at("tagSupport").get<
            ClientSymbolTagOptions>();
        if(object.contains("resolveSupport"))
            workspace_symbol_client_capabilities.resolveSupport = object.at("resolveSupport").get<
            ClientSymbolResolveOptions>();
    }

    auto to_json(nlohmann::json& object, const WorkspaceSymbolClientCapabilities&
    workspace_symbol_client_capabilities) noexcept -> void
    {
        if(workspace_symbol_client_capabilities.dynamicRegistration.has_value())
            object["dynamicRegistration"] = *workspace_symbol_client_capabilities.
            dynamicRegistration;
        if(workspace_symbol_client_capabilities.symbolKind.has_value())
            object["symbolKind"] = *workspace_symbol_client_capabilities.symbolKind;
        if(workspace_symbol_client_capabilities.tagSupport.has_value())
            object["tagSupport"] = *workspace_symbol_client_capabilities.tagSupport;
        if(workspace_symbol_client_capabilities.resolveSupport.has_value())
            object["resolveSupport"] = *workspace_symbol_client_capabilities.resolveSupport;
    }
}

#endif