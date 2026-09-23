// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_completion_list
#define lyrix_header_guard_eura_completion_list
#include "Eura/CompletionItem.hpp"
#include "Eura/CompletionItemDefaults.hpp"
#include "Eura/CompletionItemApplyKinds.hpp"

namespace Eura
{
    struct [[nodiscard]] CompletionList final
    {
        bool isIncomplete;

        std::optional<CompletionItemDefaults> itemDefaults;

        std::optional<CompletionItemApplyKinds> applyKind;

        std::vector<CompletionItem> items;
    };

    auto from_json(const nlohmann::json& object, CompletionList& completion_list) noexcept -> void;

    auto to_json(nlohmann::json& object, const CompletionList& completion_list) noexcept -> void;
}

#endif
#endif