// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Location.hpp"

namespace Eura
{
    auto Deserialize(const Json::Object& object, Location& location) noexcept -> void
    {
        location.uri = object.Retrieve("uri").As<DocumentUri>();
        Deserialize(object.Retrieve("range").As<Json::Object>(), location.range);
    }

    auto Serialize(Json::Object& object, const Location& location) noexcept -> void
    {
        object.fields.emplace_back("uri", location.uri);
        Serialize(object.NestedObject("range"), location.range);
    }
}

#endif