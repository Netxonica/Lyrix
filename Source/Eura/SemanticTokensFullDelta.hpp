// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_semantic_tokens_full_delta
#define lyrix_header_guard_eura_semantic_tokens_full_delta
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] SemanticTokensFullDelta final
    {
        std::optional<bool> delta;
    };

    auto from_json(const nlohmann::json& object, SemanticTokensFullDelta&
    semantic_tokens_full_delta) noexcept -> void;

    auto to_json(nlohmann::json& object, const SemanticTokensFullDelta& semantic_tokens_full_delta)
    noexcept -> void;
}

#endif
#endif