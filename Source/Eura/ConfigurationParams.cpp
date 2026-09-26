// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ConfigurationParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ConfigurationParams& configuration_params)
    noexcept -> void
    {
        const nlohmann::json& items = object.at("items");
        for(const nlohmann::json& item : items)
            configuration_params.items.emplace_back(item.get<ConfigurationItem>());
    }

    auto to_json(nlohmann::json& object, const ConfigurationParams& configuration_params) noexcept
    -> void
    {
        nlohmann::json items = nlohmann::json::array();
        for(const ConfigurationItem& item : configuration_params.items)
            items.emplace_back(item);
        object["items"] = items;
    }
}

#endif