// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_inline_value_context
#define lyrix_header_guard_eura_inline_value_context
#include "Eura/Range.hpp"

namespace Eura
{
    struct [[nodiscard]] InlineValueContext final
    {
        std::int32_t frameId;

        Range stoppedLocation;
    };

    auto from_json(const nlohmann::json& object, InlineValueContext& inline_value_context) noexcept
    -> void;

    auto to_json(nlohmann::json& object, const InlineValueContext& inline_value_context) noexcept
    -> void;
}

#endif
#endif