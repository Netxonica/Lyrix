// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Color.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, Color& color) noexcept -> void
    {
        color.red = object.at("red").get<double>();
        color.green = object.at("green").get<double>();
        color.blue = object.at("blue").get<double>();
        color.alpha = object.at("alpha").get<double>();
    }

    auto to_json(nlohmann::json& object, const Color& color) noexcept -> void
    {
        object["red"] = color.red;
        object["green"] = color.green;
        object["blue"] = color.blue;
        object["alpha"] = color.alpha;
    }
}

#endif