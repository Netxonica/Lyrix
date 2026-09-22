// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_selection_range
#define lyrix_header_guard_eura_selection_range
#include "Eura/Range.hpp"

namespace Eura
{
    struct [[nodiscard]] SelectionRange
    {
        Range range;

        std::optional<std::unique_ptr<SelectionRange>> parent;
    };

    auto from_json(const nlohmann::json& object, SelectionRange& selection_range) noexcept -> void;

    auto to_json(nlohmann::json& object, const SelectionRange& selection_range) noexcept -> void;
}

#endif
#endif