// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/TypeDefinitionClientCapabilities.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, TypeDefinitionClientCapabilities&
    type_definition_client_capabilities) noexcept -> void
    {
        if(object.contains("dynamicRegistration"))
            type_definition_client_capabilities.dynamicRegistration = object.at(
            "dynamicRegistration").get<bool>();
        if(object.contains("linkSupport"))
            type_definition_client_capabilities.linkSupport = object.at("linkSupport").get<bool>();
    }

    auto to_json(nlohmann::json& object, const TypeDefinitionClientCapabilities&
    type_definition_client_capabilities) noexcept -> void
    {
        if(type_definition_client_capabilities.dynamicRegistration.has_value())
            object["dynamicRegistration"] = *type_definition_client_capabilities.
            dynamicRegistration;
        if(type_definition_client_capabilities.linkSupport.has_value())
            object["linkSupport"] = *type_definition_client_capabilities.linkSupport;
    }
}

#endif