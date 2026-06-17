// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/HoverParams.hpp"

namespace Eura
{
    auto Deserialize(const Json::Object& object, HoverParams& hover_params) noexcept -> void
    {
        hover_params.textDocument = object.Retrieve("textDocument").As<Json::String>();
        Deserialize(object.Retrieve("position").As<Json::Object>(), hover_params.position);
    }

    auto Serialize(Json::Object& object, const HoverParams& hover_params) noexcept -> void
    {
        object.fields.emplace_back("textDocument", hover_params.textDocument);
        Serialize(object.NestedObject("position"), hover_params.position);
    }
}

#endif