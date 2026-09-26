// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ConfigurationItem.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ConfigurationItem& configuration_item) noexcept ->
    void
    {
        if(object.contains("scopeUri"))
            configuration_item.scopeUri = object.at("scopeUri").get<URI>();
        if(object.contains("section"))
            configuration_item.section = object.at("section").get<std::string>();
    }

    auto to_json(nlohmann::json& object, const ConfigurationItem& configuration_item) noexcept ->
    void
    {
        if(configuration_item.scopeUri.has_value())
            object["scopeUri"] = *configuration_item.scopeUri;
        if(configuration_item.section.has_value())
            object["section"] = *configuration_item.section;
    }
}

#endif