// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_insert_replace_edit
#define lyrix_header_guard_eura_insert_replace_edit
#include "Eura/Range.hpp"

namespace Eura
{
    struct [[nodiscard]] InsertReplaceEdit final
    {
        std::string newText;

        Range insert, replace;
    };

    auto from_json(const nlohmann::json& object, InsertReplaceEdit& insert_replace_edit) noexcept
    -> void;

    auto to_json(nlohmann::json& object, const InsertReplaceEdit& insert_replace_edit) noexcept ->
    void;
}

#endif
#endif