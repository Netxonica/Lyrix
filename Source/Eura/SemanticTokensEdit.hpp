// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_semantic_tokens_edit
#define lyrix_header_guard_eura_semantic_tokens_edit
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] SemanticTokensEdit final
    {
        std::uint32_t start, deleteCount;

        std::optional<std::vector<std::uint32_t>> data;
    };

    auto from_json(const nlohmann::json& object, SemanticTokensEdit& semantic_tokens_edit) noexcept
    -> void;

    auto to_json(nlohmann::json& object, const SemanticTokensEdit& semantic_tokens_edit) noexcept
    -> void;
}

#endif
#endif