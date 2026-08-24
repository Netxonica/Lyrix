// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/InlayHintClientCapabilities.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, InlayHintClientCapabilities&
    inlay_hint_client_capabilities) noexcept -> void
    {
        if(object.contains("dynamicRegistration"))
            inlay_hint_client_capabilities.dynamicRegistration = object.at("dynamicRegistration").
            get<bool>();
        if(object.contains("resolveSupport"))
            inlay_hint_client_capabilities.resolveSupport = object.at("resolveSupport").get<
            ClientInlayHintResolveOptions>();
    }

    auto to_json(nlohmann::json& object, const InlayHintClientCapabilities&
    inlay_hint_client_capabilities) noexcept -> void
    {
        if(inlay_hint_client_capabilities.dynamicRegistration.has_value())
            object["dynamicRegistration"] = *inlay_hint_client_capabilities.dynamicRegistration;
        if(inlay_hint_client_capabilities.resolveSupport.has_value())
            object["resolveSupport"] = *inlay_hint_client_capabilities.resolveSupport;
    }
}

#endif