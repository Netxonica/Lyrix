// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/InlayHint.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, InlayHint& inlay_hint) noexcept -> void
    {
        inlay_hint.position = object.at("position").get<Position>();
        const nlohmann::json& label = object.at("label");
        if(label.is_string())
            inlay_hint.label = label.get<std::string>();
        else
            inlay_hint.label = label.get<std::vector<InlayHintLabelPart>>();
        if(object.contains("kind"))
            inlay_hint.kind = object.at("kind").get<InlayHintKind>();
        if(object.contains("textEdits"))
        {
            inlay_hint.textEdits = std::vector<TextEdit>{};
            const nlohmann::json& textEdits = object.at("textEdits");
            for(const nlohmann::json& textEdit : textEdits)
                inlay_hint.textEdits->emplace_back(textEdit.get<TextEdit>());
        }
        if(object.contains("tooltip"))
        {
            const nlohmann::json& tooltip = object.at("tooltip");
            if(tooltip.is_string())
                inlay_hint.tooltip = tooltip.get<std::string>();
            else
                inlay_hint.tooltip = tooltip.get<MarkupContent>();
        }
        if(object.contains("paddingLeft"))
            inlay_hint.paddingLeft = object.at("paddingLeft").get<bool>();
        if(object.contains("paddingRight"))
            inlay_hint.paddingRight = object.at("paddingRight").get<bool>();
        if(object.contains("data"))
            inlay_hint.data = object.at("data");
    }

    auto to_json(nlohmann::json& object, const InlayHint& inlay_hint) noexcept -> void
    {
        object["position"] = inlay_hint.position;
        if(std::holds_alternative<std::string>(inlay_hint.label))
            object["label"] = std::get<std::string>(inlay_hint.label);
        else
        {
            nlohmann::json label = nlohmann::json::array();
            const std::vector<InlayHintLabelPart>& labels = std::get<std::vector<InlayHintLabelPart
            >>(inlay_hint.label);
            for(const InlayHintLabelPart& labe : labels)
                label.emplace_back(labe);
            object["label"] = label;
        }
        if(inlay_hint.kind.has_value())
            object["kind"] = *inlay_hint.kind;
        if(inlay_hint.textEdits.has_value())
        {
            nlohmann::json textEdits = nlohmann::json::array();
            for(const TextEdit& textEdit : *inlay_hint.textEdits)
                textEdits.emplace_back(textEdit);
            object["textEdits"] = textEdits;
        }
        if(inlay_hint.tooltip.has_value())
            std::visit([&object](auto&& tooltip)
            {
                object["tooltip"] = tooltip;
            }, *inlay_hint.tooltip);
        if(inlay_hint.paddingLeft.has_value())
            object["paddingLeft"] = *inlay_hint.paddingLeft;
        if(inlay_hint.paddingRight.has_value())
            object["paddingRight"] = *inlay_hint.paddingRight;
        if(inlay_hint.data.has_value())
            object["data"] = *inlay_hint.data;
    }
}

#endif