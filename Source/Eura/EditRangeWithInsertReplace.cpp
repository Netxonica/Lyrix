// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/EditRangeWithInsertReplace.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, EditRangeWithInsertReplace&
    edit_range_with_insert_replace) noexcept -> void
    {
        edit_range_with_insert_replace.insert = object.at("insert").get<Range>();
        edit_range_with_insert_replace.replace = object.at("replace").get<Range>();
    }

    auto to_json(nlohmann::json& object, const EditRangeWithInsertReplace&
    edit_range_with_insert_replace) noexcept -> void
    {
        object["insert"] = edit_range_with_insert_replace.insert;
        object["replace"] = edit_range_with_insert_replace.replace;
    }
}

#endif