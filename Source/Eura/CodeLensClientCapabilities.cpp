// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CodeLensClientCapabilities.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, CodeLensClientCapabilities&
    code_lens_client_capabilities) noexcept -> void
    {
        if(object.contains("dynamicRegistration"))
            code_lens_client_capabilities.dynamicRegistration = object.at("dynamicRegistration").
            get<bool>();
        if(object.contains("resolveSupport"))
            code_lens_client_capabilities.resolveSupport = object.at("resolveSupport").get<
            ClientCodeLensResolveOptions>();
    }

    auto to_json(nlohmann::json& object, const CodeLensClientCapabilities&
    code_lens_client_capabilities) noexcept -> void
    {
        if(code_lens_client_capabilities.dynamicRegistration.has_value())
            object["dynamicRegistration"] = *code_lens_client_capabilities.dynamicRegistration;
        if(code_lens_client_capabilities.resolveSupport.has_value())
            object["resolveSupport"] = *code_lens_client_capabilities.resolveSupport;
    }
}

#endif