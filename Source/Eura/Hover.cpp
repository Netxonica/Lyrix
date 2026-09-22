// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Hover.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, Hover& hover) noexcept -> void
    {
        hover.contents = object.at("contents").get<MarkupContent>();
        if(object.contains("range"))
            hover.range = object.at("range").get<Range>();
    }

    auto to_json(nlohmann::json& object, const Hover& hover) noexcept -> void
    {
        object["contents"] = hover.contents;
        if(hover.range.has_value())
            object["range"] = *hover.range;
    }
}

#endif