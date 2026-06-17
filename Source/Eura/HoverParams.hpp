// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_hover_params
#define lyrix_header_guard_eura_hover_params
#include "Eura/Position.hpp"

namespace Eura
{
    struct [[nodiscard]] HoverParams final
    {
        Json::String textDocument;

        Position position;
    };

    auto Deserialize(const Json::Object& object, HoverParams& hover_params) noexcept -> void;

    auto Serialize(Json::Object& object, const HoverParams& hover_params) noexcept -> void;
}

#endif
#endif