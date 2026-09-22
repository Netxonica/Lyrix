// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_semantic_tokens_partial_result
#define lyrix_header_guard_eura_semantic_tokens_partial_result
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] SemanticTokensPartialResult final
    {
        std::vector<std::uint32_t> data;
    };

    auto from_json(const nlohmann::json& object, SemanticTokensPartialResult&
    semantic_tokens_partial_result) noexcept -> void;

    auto to_json(nlohmann::json& object, const SemanticTokensPartialResult&
    semantic_tokens_partial_result) noexcept -> void;
}

#endif
#endif