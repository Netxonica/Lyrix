// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/HoverParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, HoverParams& hover_params) noexcept -> void
    {
        hover_params.textDocument = object.at("textDocument").get<std::string>();
        hover_params.position = object.at("position").get<Position>();
    }

    auto to_json(nlohmann::json& object, const HoverParams& hover_params) noexcept -> void
    {
        object["textDocument"] = hover_params.textDocument;
        object["position"] = hover_params.position;
    }
}

#endif