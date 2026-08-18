// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_text_edit
#define lyrix_header_guard_eura_text_edit
#include "Eura/Range.hpp"

namespace Eura
{
    struct [[nodiscard]] TextEdit final
    {
        Range range;

        std::string newText;
    };

    auto from_json(const nlohmann::json& object, TextEdit& text_edit) noexcept -> void;

    auto to_json(nlohmann::json& object, const TextEdit& text_edit) noexcept -> void;
}

#endif
#endif