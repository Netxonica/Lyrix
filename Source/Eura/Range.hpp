// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_range
#define lyrix_header_guard_eura_range
#include "Eura/Position.hpp"

namespace Eura
{
    struct [[nodiscard]] Range final
    {
        Position start, end;
    };

    auto Deserialize(const Json::Object& object, Range& range) noexcept -> void;

    auto Serialize(Json::Object& object, const Range& range) noexcept -> void;
}

#endif
#endif