// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ClientCodeLensResolveOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ClientCodeLensResolveOptions&
    client_code_lens_resolve_options) noexcept -> void
    {
        const nlohmann::json& properties = object.at("properties");
        for(const nlohmann::json& property : properties)
            client_code_lens_resolve_options.properties.emplace_back(property.get<std::string>());
    }

    auto to_json(nlohmann::json& object, const ClientCodeLensResolveOptions&
    client_code_lens_resolve_options) noexcept -> void
    {
        nlohmann::json properties = nlohmann::json::array();
        for(const std::string& property : client_code_lens_resolve_options.properties)
            properties.emplace_back(property);
        object["properties"] = properties;
    }
}

#endif