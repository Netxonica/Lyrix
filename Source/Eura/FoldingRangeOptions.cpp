// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/FoldingRangeOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, FoldingRangeOptions& folding_range_options)
    noexcept -> void
    {
        from_json(object, static_cast<WorkDoneProgressOptions&>(folding_range_options));
    }

    auto to_json(nlohmann::json& object, const FoldingRangeOptions& folding_range_options) noexcept
    -> void
    {
        to_json(object, static_cast<const WorkDoneProgressOptions&>(folding_range_options));
    }
}

#endif