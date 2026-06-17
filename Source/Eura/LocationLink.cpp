// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/LocationLink.hpp"

namespace Eura
{
    auto Deserialize(const Json::Object& object, LocationLink& location_link) noexcept -> void
    {
        if(object.Contains("originSelectionRange"))
        {
            Range originSelectionRange;
            Deserialize(object.Retrieve("originSelectionRange").As<Json::Object>(),
            originSelectionRange);
            location_link.originSelectionRange = originSelectionRange;
        }
        location_link.targetUri = object.Retrieve("targetUri").As<DocumentUri>();
        Deserialize(object.Retrieve("targetRange").As<Json::Object>(), location_link.targetRange);
        Deserialize(object.Retrieve("targetSelectionRange").As<Json::Object>(), location_link.
        targetSelectionRange);
    }

    auto Serialize(Json::Object& object, const LocationLink& location_link) noexcept -> void
    {
        if(location_link.originSelectionRange.has_value())
            Serialize(object.NestedObject("originSelectionRange"), *location_link.
            originSelectionRange);
        object.fields.emplace_back("targetUri", location_link.targetUri);
        Serialize(object.NestedObject("targetRange"), location_link.targetRange);
        Serialize(object.NestedObject("targetSelectionRange"), location_link.targetSelectionRange);
    }
}

#endif