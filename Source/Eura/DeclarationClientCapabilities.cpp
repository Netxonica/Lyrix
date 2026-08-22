// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DeclarationClientCapabilities.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DeclarationClientCapabilities&
    declaration_client_capabilities) noexcept -> void
    {
        if(object.contains("dynamicRegistration"))
            declaration_client_capabilities.dynamicRegistration = object.at("dynamicRegistration").
            get<bool>();
        if(object.contains("linkSupport"))
            declaration_client_capabilities.linkSupport = object.at("linkSupport").get<bool>();
    }

    auto to_json(nlohmann::json& object, const DeclarationClientCapabilities&
    declaration_client_capabilities) noexcept -> void
    {
        if(declaration_client_capabilities.dynamicRegistration.has_value())
            object["dynamicRegistration"] = *declaration_client_capabilities.dynamicRegistration;
        if(declaration_client_capabilities.linkSupport.has_value())
            object["linkSupport"] = *declaration_client_capabilities.linkSupport;
    }
}

#endif