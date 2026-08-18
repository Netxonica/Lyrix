// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/TextEdit.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, TextEdit& text_edit) noexcept -> void
    {
        text_edit.range = object.at("range").get<Range>();
        text_edit.newText = object.at("newText").get<std::string>();
    }

    auto to_json(nlohmann::json& object, const TextEdit& text_edit) noexcept -> void
    {
        object["range"] = text_edit.range;
        object["newText"] = text_edit.newText;
    }
}

#endif