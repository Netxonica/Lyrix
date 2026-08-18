// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Range.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, Range& range) noexcept -> void
    {
        range.start = object.at("start").get<Position>();
        range.end = object.at("end").get<Position>();
    }

    auto to_json(nlohmann::json& object, const Range& range) noexcept -> void
    {
        object["start"] = range.start;
        object["end"] = range.end;
    }
}

#endif