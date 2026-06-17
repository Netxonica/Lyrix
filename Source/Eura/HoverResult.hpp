// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_hover_result
#define lyrix_header_guard_eura_hover_result
#include "Eura/Any.hpp"

namespace Eura
{
    struct [[nodiscard]] HoverResult final
    {
        Json::String value;
    };

    auto Deserialize(const Json::Object& object, HoverResult& hover_result) noexcept -> void;

    auto Serialize(Json::Object& object, const HoverResult& hover_result) noexcept -> void;
}

#endif
#endif