// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_semantic_tokens_delta_params
#define lyrix_header_guard_eura_semantic_tokens_delta_params
#include "Eura/PartialResultParams.hpp"
#include "Eura/TextDocumentIdentifier.hpp"
#include "Eura/WorkDoneProgressParams.hpp"

namespace Eura
{
    struct [[nodiscard]] SemanticTokensDeltaParams final : WorkDoneProgressParams,
    PartialResultParams
    {
        TextDocumentIdentifier textDocument;

        std::string previousResultId;
    };

    auto from_json(const nlohmann::json& object, SemanticTokensDeltaParams&
    semantic_tokens_delta_params) noexcept -> void;

    auto to_json(nlohmann::json& object, const SemanticTokensDeltaParams&
    semantic_tokens_delta_params) noexcept -> void;
}

#endif
#endif