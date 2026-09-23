// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/InlineValueText.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, InlineValueText& inline_value_text) noexcept ->
    void
    {
        inline_value_text.range = object.at("range").get<Range>();
        inline_value_text.text = object.at("text").get<std::string>();
    }

    auto to_json(nlohmann::json& object, const InlineValueText& inline_value_text) noexcept -> void
    {
        object["range"] = inline_value_text.range;
        object["text"] = inline_value_text.text;
    }
}

#endif