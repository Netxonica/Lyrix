// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/HoverResult.hpp"

namespace Eura
{
    auto Deserialize(const Json::Object& object, HoverResult& hover_result) noexcept -> void
    {
        hover_result.value = object.Retrieve("value").As<Json::String>();
    }

    auto Serialize(Json::Object& object, const HoverResult& hover_result) noexcept -> void
    {
        object.fields.emplace_back("value", hover_result.value);
    }
}

#endif