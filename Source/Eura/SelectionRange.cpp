// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/SelectionRange.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, SelectionRange& selection_range) noexcept -> void
    {
        selection_range.range = object.at("range").get<Range>();
        if(object.contains("parent"))
            selection_range.parent = std::make_unique<SelectionRange>(object.at("parent").get<
            SelectionRange>());
    }

    auto to_json(nlohmann::json& object, const SelectionRange& selection_range) noexcept -> void
    {
        object["range"] = selection_range.range;
        if(selection_range.parent.has_value())
            object["parent"] = *(*selection_range.parent);
    }
}

#endif