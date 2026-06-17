// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/TextEdit.hpp"

namespace Eura
{
    auto Deserialize(const Json::Object& object, TextEdit& text_edit) noexcept -> void
    {
        Deserialize(object.Retrieve("range").As<Json::Object>(), text_edit.range);
        text_edit.newText = object.Retrieve("newText").As<Json::String>();
    }

    auto Serialize(Json::Object& object, const TextEdit& text_edit) noexcept -> void
    {
        Serialize(object.NestedObject("range"), text_edit.range);
        object.fields.emplace_back("newText", text_edit.newText);
    }
}

#endif