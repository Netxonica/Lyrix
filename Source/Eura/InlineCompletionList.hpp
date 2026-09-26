// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_inline_completion_list
#define lyrix_header_guard_eura_inline_completion_list
#include "Eura/InlineCompletionItem.hpp"

namespace Eura
{
    struct [[nodiscard]] InlineCompletionList final
    {
        std::vector<InlineCompletionItem> items;
    };

    auto from_json(const nlohmann::json& object, InlineCompletionList& inline_completion_list)
    noexcept -> void;

    auto to_json(nlohmann::json& object, const InlineCompletionList& inline_completion_list)
    noexcept -> void;
}

#endif
#endif