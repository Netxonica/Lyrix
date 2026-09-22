// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/SemanticTokens.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, SemanticTokens& semantic_tokens) noexcept -> void
    {
        if(object.contains("resultId"))
            semantic_tokens.resultId = object.at("resultId").get<std::string>();
        const nlohmann::json& data = object.at("data");
        for(const nlohmann::json& dat : data)
            semantic_tokens.data.emplace_back(dat.get<std::uint32_t>());
    }

    auto to_json(nlohmann::json& object, const SemanticTokens& semantic_tokens) noexcept -> void
    {
        if(semantic_tokens.resultId.has_value())
            object["resultId"] = *semantic_tokens.resultId;
        nlohmann::json data = nlohmann::json::array();
        for(const std::uint32_t dat : semantic_tokens.data)
            data.emplace_back(dat);
        object["data"] = data;
    }
}

#endif