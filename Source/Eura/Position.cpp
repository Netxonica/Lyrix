// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Position.hpp"

namespace Eura
{
    auto Deserialize(const Json::Object& object, Position& position) noexcept -> void
    {
        position.line = object.Retrieve("line").As<Json::Uinteger>();
        position.character = object.Retrieve("character").As<Json::Uinteger>();
    }

    auto Serialize(Json::Object& object, const Position& position) noexcept -> void
    {
        object.fields.emplace_back("line", position.line);
        object.fields.emplace_back("character", position.character);
    }
}

#endif