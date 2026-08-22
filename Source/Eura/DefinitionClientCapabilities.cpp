// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DefinitionClientCapabilities.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DefinitionClientCapabilities&
    definition_client_capabilities) noexcept -> void
    {
        if(object.contains("dynamicRegistration"))
            definition_client_capabilities.dynamicRegistration = object.at("dynamicRegistration").
            get<bool>();
        if(object.contains("linkSupport"))
            definition_client_capabilities.linkSupport = object.at("linkSupport").get<bool>();
    }

    auto to_json(nlohmann::json& object, const DefinitionClientCapabilities&
    definition_client_capabilities) noexcept -> void
    {
        if(definition_client_capabilities.dynamicRegistration.has_value())
            object["dynamicRegistration"] = *definition_client_capabilities.dynamicRegistration;
        if(definition_client_capabilities.linkSupport.has_value())
            object["linkSupport"] = *definition_client_capabilities.linkSupport;
    }
}

#endif