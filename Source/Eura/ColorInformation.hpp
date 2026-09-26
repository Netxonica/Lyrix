// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_color_information
#define lyrix_header_guard_eura_color_information
#include "Eura/Range.hpp"
#include "Eura/Color.hpp"

namespace Eura
{
    struct [[nodiscard]] ColorInformation final
    {
        Range range;
        
        Color color;
    };

    auto from_json(const nlohmann::json& object, ColorInformation& color_information) noexcept ->
    void;

    auto to_json(nlohmann::json& object, const ColorInformation& color_information) noexcept ->
    void;
}

#endif
#endif