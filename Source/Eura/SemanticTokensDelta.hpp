// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_semantic_tokens_delta
#define lyrix_header_guard_eura_semantic_tokens_delta
#include "Eura/SemanticTokensEdit.hpp"

namespace Eura
{
    struct [[nodiscard]] SemanticTokensDelta final
    {
        std::optional<std::string> resultId;

        std::vector<SemanticTokensEdit> edits;
    };

    auto from_json(const nlohmann::json& object, SemanticTokensDelta& semantic_tokens_delta)
    noexcept -> void;

    auto to_json(nlohmann::json& object, const SemanticTokensDelta& semantic_tokens_delta) noexcept
    -> void;
}

#endif
#endif