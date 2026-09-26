// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/LinkedEditingRangeParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, LinkedEditingRangeParams&
    linked_editing_range_params) noexcept -> void
    {
        from_json(object, static_cast<TextDocumentPositionParams&>(linked_editing_range_params));
        from_json(object, static_cast<WorkDoneProgressParams&>(linked_editing_range_params));
    }

    auto to_json(nlohmann::json& object, const LinkedEditingRangeParams&
    linked_editing_range_params) noexcept -> void
    {
        to_json(object, static_cast<const TextDocumentPositionParams&>(linked_editing_range_params)
        );
        to_json(object, static_cast<const WorkDoneProgressParams&>(linked_editing_range_params));
    }
}

#endif