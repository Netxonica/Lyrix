// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_location
#define lyrix_header_guard_eura_location
#include "Eura/Range.hpp"
#include "Eura/DocumentUri.hpp"

namespace Eura
{
    struct [[nodiscard]] Location final
    {
        DocumentUri uri;

        Range range;
    };

    auto Deserialize(const Json::Object& object, Location& location) noexcept -> void;

    auto Serialize(Json::Object& object, const Location& location) noexcept -> void;
}

#endif
#endif