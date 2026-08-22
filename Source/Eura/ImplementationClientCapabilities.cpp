// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ImplementationClientCapabilities.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ImplementationClientCapabilities&
    implementation_client_capabilities) noexcept -> void
    {
        if(object.contains("dynamicRegistration"))
            implementation_client_capabilities.dynamicRegistration = object.at(
            "dynamicRegistration").get<bool>();
        if(object.contains("linkSupport"))
            implementation_client_capabilities.linkSupport = object.at("linkSupport").get<bool>();
    }

    auto to_json(nlohmann::json& object, const ImplementationClientCapabilities&
    implementation_client_capabilities) noexcept -> void
    {
        if(implementation_client_capabilities.dynamicRegistration.has_value())
            object["dynamicRegistration"] = *implementation_client_capabilities.dynamicRegistration
            ;
        if(implementation_client_capabilities.linkSupport.has_value())
            object["linkSupport"] = *implementation_client_capabilities.linkSupport;
    }
}

#endif