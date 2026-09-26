// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ColorPresentation.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ColorPresentation& color_presentation) noexcept ->
    void
    {
        color_presentation.label = object.at("label").get<std::string>();
        if(object.contains("textEdit"))
            color_presentation.textEdit = object.at("textEdit").get<TextEdit>();
        if(object.contains("additionalTextEdits"))
        {
            color_presentation.additionalTextEdits = std::vector<TextEdit>{};
            const nlohmann::json& additionalTextEdits = object.at("additionalTextEdits");
            for(const nlohmann::json& additionalTextEdit : additionalTextEdits)
                color_presentation.additionalTextEdits->emplace_back(additionalTextEdit.get<
                TextEdit>());
        }
    }

    auto to_json(nlohmann::json& object, const ColorPresentation& color_presentation) noexcept ->
    void
    {
        object["label"] = color_presentation.label;
        if(color_presentation.textEdit.has_value())
            object["textEdit"] = *color_presentation.textEdit;
        if(color_presentation.additionalTextEdits.has_value())
        {
            nlohmann::json additionalTextEdits = nlohmann::json::array();
            for(const TextEdit& additionalTextEdit : *color_presentation.additionalTextEdits)
                additionalTextEdits.emplace_back(additionalTextEdit);
            object["additionalTextEdits"] = additionalTextEdits;
        }
    }
}

#endif