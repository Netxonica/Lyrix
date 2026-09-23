// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_completion_item_apply_kinds
#define lyrix_header_guard_eura_completion_item_apply_kinds
#include "Eura/Json.hpp"
#include "Eura/ApplyKind.hpp"

namespace Eura
{
    struct [[nodiscard]] CompletionItemApplyKinds final
    {
        std::optional<ApplyKind> commitCharacters, data;
    };

    auto from_json(const nlohmann::json& object, CompletionItemApplyKinds&
    completion_item_apply_kinds) noexcept -> void;

    auto to_json(nlohmann::json& object, const CompletionItemApplyKinds&
    completion_item_apply_kinds) noexcept -> void;
}

#endif
#endif