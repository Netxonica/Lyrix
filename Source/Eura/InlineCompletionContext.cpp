// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/InlineCompletionContext.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, InlineCompletionContext& inline_completion_context
    ) noexcept -> void
    {
        inline_completion_context.triggerKind = object.at("triggerKind").get<
        InlineCompletionTriggerKind>();
        if(object.contains("selectedCompletionInfo"))
            inline_completion_context.selectedCompletionInfo = object.at("selectedCompletionInfo").
            get<SelectedCompletionInfo>();
    }

    auto to_json(nlohmann::json& object, const InlineCompletionContext& inline_completion_context)
    noexcept -> void
    {
        object["triggerKind"] = inline_completion_context.triggerKind;
        if(inline_completion_context.selectedCompletionInfo.has_value())
            object["selectedCompletionInfo"] = *inline_completion_context.selectedCompletionInfo;
    }
}

#endif