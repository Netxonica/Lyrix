// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/SemanticTokensFullDelta.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, SemanticTokensFullDelta&
    semantic_tokens_full_delta) noexcept -> void
    {
        if(object.contains("delta"))
            semantic_tokens_full_delta.delta = object.at("delta").get<bool>();
    }

    auto to_json(nlohmann::json& object, const SemanticTokensFullDelta& semantic_tokens_full_delta)
    noexcept -> void
    {
        if(semantic_tokens_full_delta.delta.has_value())
            object["delta"] = *semantic_tokens_full_delta.delta;
    }
}

#endif