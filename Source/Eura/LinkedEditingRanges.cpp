// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/LinkedEditingRanges.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, LinkedEditingRanges& linked_editing_ranges)
    noexcept -> void
    {
        const nlohmann::json& ranges = object.at("ranges");
        for(const nlohmann::json& range : ranges)
            linked_editing_ranges.ranges.emplace_back(range.get<Range>());
        if(object.contains("wordPattern"))
            linked_editing_ranges.wordPattern = object.at("wordPattern").get<std::string>();
    }

    auto to_json(nlohmann::json& object, const LinkedEditingRanges& linked_editing_ranges) noexcept
    -> void
    {
        nlohmann::json ranges = nlohmann::json::array();
        for(const Range& range : linked_editing_ranges.ranges)
            ranges.emplace_back(range);
        object["ranges"] = ranges;
        if(linked_editing_ranges.wordPattern.has_value())
            object["wordPattern"] = *linked_editing_ranges.wordPattern;
    }
}

#endif