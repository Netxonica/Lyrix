// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ReferenceClientCapabilities.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ReferenceClientCapabilities&
    reference_client_capabilities) noexcept -> void
    {
        if(object.contains("dynamicRegistration"))
            reference_client_capabilities.dynamicRegistration = object.at("dynamicRegistration").
            get<bool>();
    }

    auto to_json(nlohmann::json& object, const ReferenceClientCapabilities&
    reference_client_capabilities) noexcept -> void
    {
        if(reference_client_capabilities.dynamicRegistration.has_value())
            object["dynamicRegistration"] = *reference_client_capabilities.dynamicRegistration;
    }
}

#endif