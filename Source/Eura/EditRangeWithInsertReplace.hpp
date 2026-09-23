// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_edit_range_with_insert_replace
#define lyrix_header_guard_eura_edit_range_with_insert_replace
#include "Eura/Range.hpp"

namespace Eura
{
    struct [[nodiscard]] EditRangeWithInsertReplace final
    {
        Range insert, replace;
    };

    auto from_json(const nlohmann::json& object, EditRangeWithInsertReplace&
    edit_range_with_insert_replace) noexcept -> void;

    auto to_json(nlohmann::json& object, const EditRangeWithInsertReplace&
    edit_range_with_insert_replace) noexcept -> void;
}

#endif
#endif