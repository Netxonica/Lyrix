// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/MarkupContent.hpp"

namespace Eura
{
    auto Deserialize(const Json::Object& object, MarkupContent& markup_content) noexcept -> void
    {
        markup_content.kind = object.Retrieve("kind").As<MarkupKind>();
        markup_content.value = object.Retrieve("value").As<Json::String>();
    }

    auto Serialize(Json::Object& object, const MarkupContent& markup_content) noexcept -> void
    {
        object.fields.emplace_back("kind", markup_content.kind);
        object.fields.emplace_back("value", markup_content.value);
    }
}

#endif