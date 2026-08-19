// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_markup_content
#define lyrix_header_guard_eura_markup_content
#include "Eura/Json.hpp"
#include "Eura/MarkupKind.hpp"

namespace Eura
{
    struct [[nodiscard]] MarkupContent final
    {
        MarkupKind kind;

        std::string value;
    };

    auto from_json(const nlohmann::json& object, MarkupContent& markup_content) noexcept -> void;

    auto to_json(nlohmann::json& object, const MarkupContent& markup_content) noexcept -> void;
}

#endif
#endif