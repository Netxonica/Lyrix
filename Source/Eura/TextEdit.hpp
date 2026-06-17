// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_text_edit
#define lyrix_header_guard_eura_text_edit
#include "Eura/Range.hpp"

namespace Eura
{
    struct [[nodiscard]] TextEdit
    {
        Range range;

        Json::String newText;
    };

    auto Deserialize(const Json::Object& object, TextEdit& text_edit) noexcept -> void;

    auto Serialize(Json::Object& object, const TextEdit& text_edit) noexcept -> void;
}

#endif
#endif