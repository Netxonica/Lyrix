// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/HoverClientCapabilities.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, HoverClientCapabilities& hover_client_capabilities
    ) noexcept -> void
    {
        if(object.contains("dynamicRegistration"))
            hover_client_capabilities.dynamicRegistration = object.at("dynamicRegistration").get<
            bool>();
        if(object.contains("contentFormat"))
        {
            hover_client_capabilities.contentFormat = std::vector<MarkupKind>{};
            const nlohmann::json& contentFormat = object.at("contentFormat");
            for(const nlohmann::json& content : contentFormat)
                hover_client_capabilities.contentFormat->emplace_back(content.get<MarkupKind>());
        }
    }

    auto to_json(nlohmann::json& object, const HoverClientCapabilities& hover_client_capabilities)
    noexcept -> void
    {
        if(hover_client_capabilities.dynamicRegistration.has_value())
            object["dynamicRegistration"] = *hover_client_capabilities.dynamicRegistration;
        if(hover_client_capabilities.contentFormat.has_value())
        {
            nlohmann::json contentFormat = nlohmann::json::array();
            for(const MarkupKind& content : *hover_client_capabilities.contentFormat)
                contentFormat.emplace_back(content);
            object["contentFormat"] = contentFormat;
        }
    }
}

#endif