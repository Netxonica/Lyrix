// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_semantic_tokens
#define lyrix_header_guard_eura_semantic_tokens
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] SemanticTokens final
    {
        std::optional<std::string> resultId;

        std::vector<std::uint32_t> data;
    };

    auto from_json(const nlohmann::json& object, SemanticTokens& semantic_tokens) noexcept -> void;

    auto to_json(nlohmann::json& object, const SemanticTokens& semantic_tokens) noexcept -> void;
}

#endif
#endif