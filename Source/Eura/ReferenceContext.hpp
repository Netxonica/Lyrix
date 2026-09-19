// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_reference_context
#define lyrix_header_guard_eura_reference_context
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] ReferenceContext final
    {
        bool includeDeclaration;
    };

    auto from_json(const nlohmann::json& object, ReferenceContext& reference_context) noexcept ->
    void;

    auto to_json(nlohmann::json& object, const ReferenceContext& reference_context) noexcept ->
    void;
}

#endif
#endif