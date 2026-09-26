// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_inline_completion_params
#define lyrix_header_guard_eura_inline_completion_params
#include "Eura/WorkDoneProgressParams.hpp"
#include "Eura/InlineCompletionContext.hpp"
#include "Eura/TextDocumentPositionParams.hpp"

namespace Eura
{
    struct [[nodiscard]] InlineCompletionParams final : TextDocumentPositionParams,
    WorkDoneProgressParams
    {
        InlineCompletionContext context;
    };

    auto from_json(const nlohmann::json& object, InlineCompletionParams& inline_completion_params)
    noexcept -> void;

    auto to_json(nlohmann::json& object, const InlineCompletionParams& inline_completion_params)
    noexcept -> void;
}

#endif
#endif