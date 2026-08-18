// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/HoverResult.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, HoverResult& hover_result) noexcept -> void
    {
        hover_result.value = object.at("value").get<std::string>();
    }

    auto to_json(nlohmann::json& object, const HoverResult& hover_result) noexcept -> void
    {
        object["value"] = hover_result.value;
    }
}

#endif