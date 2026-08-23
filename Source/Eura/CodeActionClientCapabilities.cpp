// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CodeActionClientCapabilities.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, CodeActionClientCapabilities&
    code_action_client_capabilities) noexcept -> void
    {
        if(object.contains("dynamicRegistration"))
            code_action_client_capabilities.dynamicRegistration = object.at("dynamicRegistration").
            get<bool>();
        if(object.contains("codeActionLiteralSupport"))
            code_action_client_capabilities.codeActionLiteralSupport = object.at(
            "codeActionLiteralSupport").get<ClientCodeActionLiteralOptions>();
        if(object.contains("isPreferredSupport"))
            code_action_client_capabilities.isPreferredSupport = object.at("isPreferredSupport").
            get<bool>();
        if(object.contains("disabledSupport"))
            code_action_client_capabilities.disabledSupport = object.at("disabledSupport").get<bool
            >();
        if(object.contains("dataSupport"))
            code_action_client_capabilities.dataSupport = object.at("dataSupport").get<bool>();
        if(object.contains("resolveSupport"))
            code_action_client_capabilities.resolveSupport = object.at("resolveSupport").get<
            ClientCodeActionResolveOptions>();
        if(object.contains("honorsChangeAnnotations"))
            code_action_client_capabilities.honorsChangeAnnotations = object.at(
            "honorsChangeAnnotations").get<bool>();
        if(object.contains("documentationSupport"))
            code_action_client_capabilities.documentationSupport = object.at("documentationSupport"
            ).get<bool>();
        if(object.contains("tagSupport"))
            code_action_client_capabilities.tagSupport = object.at("tagSupport").get<
            CodeActionTagOptions>();
    }

    auto to_json(nlohmann::json& object, const CodeActionClientCapabilities&
    code_action_client_capabilities) noexcept -> void
    {
        if(code_action_client_capabilities.dynamicRegistration.has_value())
            object["dynamicRegistration"] = *code_action_client_capabilities.dynamicRegistration;
        if(code_action_client_capabilities.codeActionLiteralSupport.has_value())
            object["codeActionLiteralSupport"] = *code_action_client_capabilities.
            codeActionLiteralSupport;
        if(code_action_client_capabilities.isPreferredSupport.has_value())
            object["isPreferredSupport"] = *code_action_client_capabilities.isPreferredSupport;
        if(code_action_client_capabilities.disabledSupport.has_value())
            object["disabledSupport"] = *code_action_client_capabilities.disabledSupport;
        if(code_action_client_capabilities.dataSupport.has_value())
            object["dataSupport"] = *code_action_client_capabilities.dataSupport;
        if(code_action_client_capabilities.resolveSupport.has_value())
            object["resolveSupport"] = *code_action_client_capabilities.resolveSupport;
        if(code_action_client_capabilities.honorsChangeAnnotations.has_value())
            object["honorsChangeAnnotations"] = *code_action_client_capabilities.
            honorsChangeAnnotations;
        if(code_action_client_capabilities.documentationSupport.has_value())
            object["documentationSupport"] = *code_action_client_capabilities.documentationSupport;
        if(code_action_client_capabilities.tagSupport.has_value())
            object["tagSupport"] = *code_action_client_capabilities.tagSupport;
    }
}

#endif