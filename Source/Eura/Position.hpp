// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_position
#define lyrix_header_guard_eura_position
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] Position final
    {
        std::uint32_t line, character;
    };

    auto from_json(const nlohmann::json& object, Position& position) noexcept -> void;

    auto to_json(nlohmann::json& object, const Position& position) noexcept -> void;
}

#endif
#endif