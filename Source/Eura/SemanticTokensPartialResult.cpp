// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/SemanticTokensPartialResult.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, SemanticTokensPartialResult&
    semantic_tokens_partial_result) noexcept -> void
    {
        const nlohmann::json& data = object.at("data");
        for(const nlohmann::json& dat : data)
            semantic_tokens_partial_result.data.emplace_back(dat.get<std::uint32_t>());
    }

    auto to_json(nlohmann::json& object, const SemanticTokensPartialResult&
    semantic_tokens_partial_result) noexcept -> void
    {
        nlohmann::json data = nlohmann::json::array();
        for(const std::uint32_t dat : semantic_tokens_partial_result.data)
            data.emplace_back(dat);
        object["data"] = data;
    }
}

#endif