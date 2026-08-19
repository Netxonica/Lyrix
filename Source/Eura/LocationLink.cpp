// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/LocationLink.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, LocationLink& location_link) noexcept -> void
    {
        if(object.contains("originSelectionRange"))
            location_link.originSelectionRange = object.at("originSelectionRange").get<Range>();
        location_link.targetUri = object.at("targetUri").get<DocumentUri>();
        location_link.targetRange = object.at("targetRange").get<Range>();
        location_link.targetSelectionRange = object.at("targetSelectionRange").get<Range>();
    }

    auto to_json(nlohmann::json& object, const LocationLink& location_link) noexcept -> void
    {
        if(location_link.originSelectionRange.has_value())
            object["originSelectionRange"] = *location_link.originSelectionRange;
        object["targetUri"] = location_link.targetUri;
        object["targetRange"] = location_link.targetRange;
        object["targetSelectionRange"] = location_link.targetSelectionRange;
    }
}

#endif