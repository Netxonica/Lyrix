// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_semantic_tokens_range_params
#define lyrix_header_guard_eura_semantic_tokens_range_params
#include "Eura/Range.hpp"
#include "Eura/PartialResultParams.hpp"
#include "Eura/TextDocumentIdentifier.hpp"
#include "Eura/WorkDoneProgressParams.hpp"

namespace Eura
{
    struct [[nodiscard]] SemanticTokensRangeParams final : WorkDoneProgressParams,
    PartialResultParams
    {
        TextDocumentIdentifier textDocument;

        Range range;
    };

    auto from_json(const nlohmann::json& object, SemanticTokensRangeParams&
    semantic_tokens_range_params) noexcept -> void;

    auto to_json(nlohmann::json& object, const SemanticTokensRangeParams&
    semantic_tokens_range_params) noexcept -> void;
}

#endif
#endif