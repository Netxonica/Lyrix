// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_semantic_tokens_options
#define lyrix_header_guard_eura_semantic_tokens_options
#include "Eura/Empty.hpp"
#include "Eura/SemanticTokensLegend.hpp"
#include "Eura/WorkDoneProgressOptions.hpp"
#include "Eura/SemanticTokensFullDelta.hpp"

namespace Eura
{
    struct [[nodiscard]] SemanticTokensOptions final : WorkDoneProgressOptions
    {
        SemanticTokensLegend legend;

        std::optional<std::variant<bool, Empty>> range;

        std::optional<std::variant<bool, SemanticTokensFullDelta>> full;
    };

    auto from_json(const nlohmann::json& object, SemanticTokensOptions& semantic_tokens_options)
    noexcept -> void;

    auto to_json(nlohmann::json& object, const SemanticTokensOptions& semantic_tokens_options)
    noexcept -> void;
}

#endif
#endif