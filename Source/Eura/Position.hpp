// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_position
#define lyrix_header_guard_eura_position
#include "Eura/Any.hpp"

namespace Eura
{
    struct [[nodiscard]] Position final
    {
        Json::Uinteger line, character;
    };

    auto Deserialize(const Json::Object& object, Position& position) noexcept -> void;

    auto Serialize(Json::Object& object, const Position& position) noexcept -> void;
}

#endif
#endif