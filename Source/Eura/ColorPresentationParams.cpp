// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ColorPresentationParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ColorPresentationParams& color_presentation_params
    ) noexcept -> void
    {
        from_json(object, static_cast<WorkDoneProgressParams&>(color_presentation_params));
        from_json(object, static_cast<PartialResultParams&>(color_presentation_params));
        color_presentation_params.textDocument = object.at("textDocument").get<
        TextDocumentIdentifier>();
        color_presentation_params.color = object.at("color").get<Color>();
        color_presentation_params.range = object.at("range").get<Range>();
    }

    auto to_json(nlohmann::json& object, const ColorPresentationParams& color_presentation_params)
    noexcept -> void
    {
        to_json(object, static_cast<const WorkDoneProgressParams&>(color_presentation_params));
        to_json(object, static_cast<const PartialResultParams&>(color_presentation_params));
        object["textDocument"] = color_presentation_params.textDocument;
        object["color"] = color_presentation_params.color;
        object["range"] = color_presentation_params.range;
    }
}

#endif