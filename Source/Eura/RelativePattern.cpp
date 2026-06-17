// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/RelativePattern.hpp"

namespace Eura
{
    auto Deserialize(const Json::Object& object, RelativePattern& relative_pattern) noexcept ->
    void
    {
        const Json::Any& baseUri = object.Retrieve("baseUri");
        if(baseUri.IsString())
            relative_pattern.baseUri = baseUri.As<URI>();
        else if(baseUri.IsObject())
        {
            WorkspaceFolder workspace_folder;
            Deserialize(baseUri.As<Json::Object>(), workspace_folder);
            relative_pattern.baseUri = workspace_folder;
        }
        else
            std::abort();
        relative_pattern.pattern = object.Retrieve("pattern").As<Pattern>();
    }

    auto Serialize(Json::Object& object, const RelativePattern& relative_pattern) noexcept -> void
    {
        if(std::holds_alternative<WorkspaceFolder>(relative_pattern.baseUri))
            Serialize(object.NestedObject("baseUri"), std::get<WorkspaceFolder>(relative_pattern.
            baseUri));
        else
            object.fields.emplace_back("baseUri", std::get<URI>(relative_pattern.baseUri));
        object.fields.emplace_back("pattern", relative_pattern.pattern);
    }
}

#endif