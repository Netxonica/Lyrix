// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/StringValue.hpp"

namespace Eura
{
    auto Deserialize(const Json::Object& object, StringValue& string_value) noexcept -> void
    {
        string_value.kind = object.Retrieve("kind").As<Json::String>();
        string_value.value = object.Retrieve("value").As<Json::String>();
    }

    auto Serialize(Json::Object& object, const StringValue& string_value) noexcept -> void
    {
        object.fields.emplace_back("kind", string_value.kind);
        object.fields.emplace_back("value", string_value.value);
    }
}

#endif