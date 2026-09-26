// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_linked_editing_ranges
#define lyrix_header_guard_eura_linked_editing_ranges
#include "Eura/Range.hpp"

namespace Eura
{
    struct [[nodiscard]] LinkedEditingRanges final
    {
        std::vector<Range> ranges;

        std::optional<std::string> wordPattern;
    };

    auto from_json(const nlohmann::json& object, LinkedEditingRanges& linked_editing_ranges)
    noexcept -> void;

    auto to_json(nlohmann::json& object, const LinkedEditingRanges& linked_editing_ranges) noexcept
    -> void;
}

#endif
#endif