// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/InlayHintLabelPart.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, InlayHintLabelPart& inlay_hint_label_part)
    noexcept -> void
    {
        inlay_hint_label_part.value = object.at("value").get<std::string>();
        if(object.contains("tooltip"))
        {
            const nlohmann::json& tooltip = object.at("tooltip");
            if(tooltip.is_string())
                inlay_hint_label_part.tooltip = tooltip.get<std::string>();
            else
                inlay_hint_label_part.tooltip = tooltip.get<MarkupContent>();
        }
        if(object.contains("location"))
            inlay_hint_label_part.location = object.at("location").get<Location>();
        if(object.contains("command"))
            inlay_hint_label_part.command = object.at("command").get<Command>();
    }

    auto to_json(nlohmann::json& object, const InlayHintLabelPart& inlay_hint_label_part) noexcept
    -> void
    {
        object["value"] = inlay_hint_label_part.value;
        if(inlay_hint_label_part.tooltip.has_value())
            std::visit([&object](auto&& tooltip)
            {
                object["tooltip"] = tooltip;
            }, *inlay_hint_label_part.tooltip);
        if(inlay_hint_label_part.location.has_value())
            object["location"] = *inlay_hint_label_part.location;
        if(inlay_hint_label_part.command.has_value())
            object["command"] = *inlay_hint_label_part.command;
    }
}

#endif