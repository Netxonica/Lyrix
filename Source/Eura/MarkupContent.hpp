// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_markup_content
#define lyrix_header_guard_eura_markup_content
#include "Eura/Any.hpp"
#include "Eura/MarkupKind.hpp"

namespace Eura
{
    struct [[nodiscard]] MarkupContent final
    {
        MarkupKind kind;

        Json::String value;
    };

    auto Deserialize(const Json::Object& object, MarkupContent& markup_content) noexcept -> void;

    auto Serialize(Json::Object& object, const MarkupContent& markup_content) noexcept -> void;
}

#endif
#endif