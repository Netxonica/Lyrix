// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_semantic_tokens_legend
#define lyrix_header_guard_eura_semantic_tokens_legend
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] SemanticTokensLegend final
    {
        std::vector<std::string> tokenTypes, tokenModifiers;
    };

    auto from_json(const nlohmann::json& object, SemanticTokensLegend& semantic_tokens_legend)
    noexcept -> void;

    auto to_json(nlohmann::json& object, const SemanticTokensLegend& semantic_tokens_legend)
    noexcept -> void;
}

#endif
#endif