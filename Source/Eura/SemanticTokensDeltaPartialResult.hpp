// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_semantic_tokens_delta_partial_result
#define lyrix_header_guard_eura_semantic_tokens_delta_partial_result
#include "Eura/SemanticTokensEdit.hpp"

namespace Eura
{
    struct [[nodiscard]] SemanticTokensDeltaPartialResult final
    {
        std::vector<SemanticTokensEdit> edits;
    };

    auto from_json(const nlohmann::json& object, SemanticTokensDeltaPartialResult&
    semantic_tokens_delta_partial_result) noexcept -> void;

    auto to_json(nlohmann::json& object, const SemanticTokensDeltaPartialResult&
    semantic_tokens_delta_partial_result) noexcept -> void;
}

#endif
#endif