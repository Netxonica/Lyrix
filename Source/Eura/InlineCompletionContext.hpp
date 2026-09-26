// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_inline_completion_context
#define lyrix_header_guard_eura_inline_completion_context
#include "Eura/SelectedCompletionInfo.hpp"
#include "Eura/InlineCompletionTriggerKind.hpp"

namespace Eura
{
    struct [[nodiscard]] InlineCompletionContext final
    {
        InlineCompletionTriggerKind triggerKind;

        std::optional<SelectedCompletionInfo> selectedCompletionInfo;
    };

    auto from_json(const nlohmann::json& object, InlineCompletionContext& inline_completion_context
    ) noexcept -> void;

    auto to_json(nlohmann::json& object, const InlineCompletionContext& inline_completion_context)
    noexcept -> void;
}

#endif
#endif