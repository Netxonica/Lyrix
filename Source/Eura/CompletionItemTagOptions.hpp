// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_completion_item_tag_options
#define lyrix_header_guard_eura_completion_item_tag_options
#include "Eura/Json.hpp"
#include "Eura/CompletionItemTag.hpp"

namespace Eura
{
    struct [[nodiscard]] CompletionItemTagOptions final
    {
        std::vector<CompletionItemTag> valueSet;
    };

    auto from_json(const nlohmann::json& object, CompletionItemTagOptions&
    completion_item_tag_options) noexcept -> void;

    auto to_json(nlohmann::json& object, const CompletionItemTagOptions&
    completion_item_tag_options) noexcept -> void;
}

#endif
#endif