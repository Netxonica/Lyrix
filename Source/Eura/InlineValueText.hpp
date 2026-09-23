// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_inline_value_text
#define lyrix_header_guard_eura_inline_value_text
#include "Eura/Range.hpp"

namespace Eura
{
    struct [[nodiscard]] InlineValueText final
    {
        Range range;

        std::string text;
    };

    auto from_json(const nlohmann::json& object, InlineValueText& inline_value_text) noexcept ->
    void;

    auto to_json(nlohmann::json& object, const InlineValueText& inline_value_text) noexcept -> void
    ;
}

#endif
#endif