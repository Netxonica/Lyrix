// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/MarkdownClientCapabilities.hpp"

namespace Eura
{
    auto Deserialize(const Json::Object& object, MarkdownClientCapabilities&
    markdown_client_capabilities) noexcept -> void
    {
        markdown_client_capabilities.parser = object.Retrieve("parser").As<Json::String>();
        if(object.Contains("version"))
            markdown_client_capabilities.version = object.Retrieve("version").As<Json::String>();
        if(object.Contains("allowedTags"))
        {
            markdown_client_capabilities.allowedTags = std::vector<Json::String>{};
            const Json::Array& allowedTags = object.Retrieve("allowedTags").As<Json::Array>();
            for(const Json::Any& allowedTag : allowedTags)
                markdown_client_capabilities.allowedTags->emplace_back(allowedTag.As<Json::String>(
                ));
        }
    }

    auto Serialize(Json::Object& object, const MarkdownClientCapabilities&
    markdown_client_capabilities) noexcept -> void
    {
        object.fields.emplace_back("parser", markdown_client_capabilities.parser);
        if(markdown_client_capabilities.version.has_value())
            object.fields.emplace_back("version", *markdown_client_capabilities.version);
        if(markdown_client_capabilities.allowedTags.has_value())
        {
            Json::Array& allowedTags = object.NestedArray("allowedTags");
            for(const Json::String& allowedTag : *markdown_client_capabilities.allowedTags)
                allowedTags.emplace_back(allowedTag);
        }
    }
}

#endif