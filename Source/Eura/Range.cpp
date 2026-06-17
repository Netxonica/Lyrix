// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Range.hpp"

namespace Eura
{
    auto Deserialize(const Json::Object& object, Range& range) noexcept -> void
    {
        Deserialize(object.Retrieve("start").As<Json::Object>(), range.start);
        Deserialize(object.Retrieve("end").As<Json::Object>(), range.end);
    }

    auto Serialize(Json::Object& object, const Range& range) noexcept -> void
    {
        Serialize(object.NestedObject("start"), range.start);
        Serialize(object.NestedObject("end"), range.end);
    }
}

#endif