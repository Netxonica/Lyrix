// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/SemanticTokensDelta.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, SemanticTokensDelta& semantic_tokens_delta)
    noexcept -> void
    {
        if(object.contains("resultId"))
            semantic_tokens_delta.resultId = object.at("resultId").get<std::string>();
        const nlohmann::json& edits = object.at("edits");
        for(const nlohmann::json& edit : edits)
            semantic_tokens_delta.edits.emplace_back(edit.get<SemanticTokensEdit>());
    }

    auto to_json(nlohmann::json& object, const SemanticTokensDelta& semantic_tokens_delta) noexcept
    -> void
    {
        if(semantic_tokens_delta.resultId.has_value())
            object["resultId"] = *semantic_tokens_delta.resultId;
        nlohmann::json edits = nlohmann::json::array();
        for(const SemanticTokensEdit& edit : semantic_tokens_delta.edits)
            edits.emplace_back(edit);
        object["edits"] = edits;
    }
}

#endif