// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ColorInformation.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ColorInformation& color_information) noexcept ->
    void
    {
        color_information.range = object.at("range").get<Range>();
        color_information.color = object.at("color").get<Color>();
    }

    auto to_json(nlohmann::json& object, const ColorInformation& color_information) noexcept ->
    void
    {
        object["range"] = color_information.range;
        object["color"] = color_information.color;
    }
}

#endif