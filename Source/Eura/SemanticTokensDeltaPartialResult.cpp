// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/SemanticTokensDeltaPartialResult.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, SemanticTokensDeltaPartialResult&
    semantic_tokens_delta_partial_result) noexcept -> void
    {
        const nlohmann::json& edits = object.at("edits");
        for(const nlohmann::json& edit : edits)
            semantic_tokens_delta_partial_result.edits.emplace_back(edit.get<SemanticTokensEdit>())
            ;
    }

    auto to_json(nlohmann::json& object, const SemanticTokensDeltaPartialResult&
    semantic_tokens_delta_partial_result) noexcept -> void
    {
        nlohmann::json edits = nlohmann::json::array();
        for(const SemanticTokensEdit& edit : semantic_tokens_delta_partial_result.edits)
            edits.emplace_back(edit);
        object["edits"] = edits;
    }
}

#endif