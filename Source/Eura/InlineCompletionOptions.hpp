// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_inline_completion_options
#define lyrix_header_guard_eura_inline_completion_options
#include "Eura/WorkDoneProgressOptions.hpp"

namespace Eura
{
    struct [[nodiscard]] InlineCompletionOptions final : WorkDoneProgressOptions{};

    auto from_json(const nlohmann::json& object, InlineCompletionOptions& inline_completion_options
    ) noexcept -> void;

    auto to_json(nlohmann::json& object, const InlineCompletionOptions& inline_completion_options)
    noexcept -> void;
}

#endif
#endif