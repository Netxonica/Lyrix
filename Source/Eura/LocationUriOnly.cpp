// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/LocationUriOnly.hpp"

namespace Eura
{
    auto Deserialize(const Json::Object& object, LocationUriOnly& location_uri_only) noexcept ->
    void
    {
        location_uri_only.uri = object.Retrieve("uri").As<DocumentUri>();
    }

    auto Serialize(Json::Object& object, const LocationUriOnly& location_uri_only) noexcept -> void
    {
        object.fields.emplace_back("uri", location_uri_only.uri);
    }
}

#endif