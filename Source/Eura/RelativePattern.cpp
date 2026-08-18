// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/RelativePattern.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, RelativePattern& relative_pattern) noexcept ->
    void
    {
        const nlohmann::json& baseUri = object.at("baseUri");
        if(baseUri.is_object())
            relative_pattern.baseUri = baseUri.get<WorkspaceFolder>();
        else
            relative_pattern.baseUri = baseUri.get<URI>();
        relative_pattern.pattern = object.at("pattern").get<Pattern>();
    }

    auto to_json(nlohmann::json& object, const RelativePattern& relative_pattern) noexcept -> void
    {
        std::visit([&object](auto&& baseUri)
        {
            object["baseUri"] = baseUri;
        }, relative_pattern.baseUri);
        object["pattern"] = relative_pattern.pattern;
    }
}

#endif