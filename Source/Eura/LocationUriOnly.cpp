// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/LocationUriOnly.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, LocationUriOnly& location_uri_only) noexcept ->
    void
    {
        location_uri_only.uri = object.at("uri").get<DocumentUri>();
    }

    auto to_json(nlohmann::json& object, const LocationUriOnly& location_uri_only) noexcept -> void
    {
        object["uri"] = location_uri_only.uri;
    }
}

#endif