// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_hover
#define lyrix_header_guard_eura_hover
#include "Eura/Range.hpp"
#include "Eura/MarkupContent.hpp"

namespace Eura
{
    struct [[nodiscard]] Hover final
    {
        MarkupContent contents;

        std::optional<Range> range;
    };

    auto from_json(const nlohmann::json& object, Hover& hover) noexcept -> void;

    auto to_json(nlohmann::json& object, const Hover& hover) noexcept -> void;
}

#endif
#endif