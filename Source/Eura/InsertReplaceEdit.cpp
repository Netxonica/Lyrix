// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/InsertReplaceEdit.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, InsertReplaceEdit& insert_replace_edit) noexcept
    -> void
    {
        insert_replace_edit.newText = object.at("newText").get<std::string>();
        insert_replace_edit.insert = object.at("insert").get<Range>();
        insert_replace_edit.replace = object.at("replace").get<Range>();
    }

    auto to_json(nlohmann::json& object, const InsertReplaceEdit& insert_replace_edit) noexcept ->
    void
    {
        object["newText"] = insert_replace_edit.newText;
        object["insert"] = insert_replace_edit.insert;
        object["replace"] = insert_replace_edit.replace;
    }
}

#endif