// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_color
#define lyrix_header_guard_eura_color
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] Color final
    {
        double red, green, blue, alpha;
    };

    auto from_json(const nlohmann::json& object, Color& color) noexcept -> void;

    auto to_json(nlohmann::json& object, const Color& color) noexcept -> void;
}

#endif
#endif