// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/MarkdownClientCapabilities.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, MarkdownClientCapabilities&
    markdown_client_capabilities) noexcept -> void
    {
        markdown_client_capabilities.parser = object.at("parser").get<std::string>();
        if(object.contains("version"))
            markdown_client_capabilities.version = object.at("version").get<std::string>();
        if(object.contains("allowedTags"))
        {
            markdown_client_capabilities.allowedTags = std::vector<std::string>{};
            const nlohmann::json& allowedTags = object.at("allowedTags");
            for(const nlohmann::json& allowedTag : allowedTags)
                markdown_client_capabilities.allowedTags->emplace_back(allowedTag.get<std::string>(
                ));
        }
    }

    auto to_json(nlohmann::json& object, const MarkdownClientCapabilities&
    markdown_client_capabilities) noexcept -> void
    {
        object["parser"] = markdown_client_capabilities.parser;
        if(markdown_client_capabilities.version.has_value())
            object["version"] = *markdown_client_capabilities.version;
        if(markdown_client_capabilities.allowedTags.has_value())
        {
            nlohmann::json allowedTags = nlohmann::json::array();
            for(const std::string& allowedTag : *markdown_client_capabilities.allowedTags)
                allowedTags.emplace_back(allowedTag);
            object["allowedTags"] = allowedTags;
        }
    }
}

#endif