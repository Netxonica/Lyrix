// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Position.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, Position& position) noexcept -> void
    {
        position.line = object.at("line").get<std::uint32_t>();
        position.character = object.at("character").get<std::uint32_t>();
    }

    auto to_json(nlohmann::json& object, const Position& position) noexcept -> void
    {
        object["line"] = position.line;
        object["character"] = position.character;
    }
}

#endif