// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Location.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, Location& location) noexcept -> void
    {
        location.uri = object.at("uri").get<DocumentUri>();
        location.range = object.at("range").get<Range>();
    }

    auto to_json(nlohmann::json& object, const Location& location) noexcept -> void
    {
        object["uri"] = location.uri;
        object["range"] = location.range;
    }
}

#endif