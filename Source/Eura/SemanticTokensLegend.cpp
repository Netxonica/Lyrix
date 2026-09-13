// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/SemanticTokensLegend.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, SemanticTokensLegend& semantic_tokens_legend)
    noexcept -> void
    {
        const nlohmann::json& tokenTypes = object.at("tokenTypes");
        for(const nlohmann::json& tokenType : tokenTypes)
            semantic_tokens_legend.tokenTypes.emplace_back(tokenType.get<std::string>());
        const nlohmann::json& tokenModifiers = object.at("tokenModifiers");
        for(const nlohmann::json& tokenModifier : tokenModifiers)
            semantic_tokens_legend.tokenModifiers.emplace_back(tokenModifier.get<std::string>());
    }

    auto to_json(nlohmann::json& object, const SemanticTokensLegend& semantic_tokens_legend)
    noexcept -> void
    {
        nlohmann::json tokenTypes = nlohmann::json::array();
        for(const std::string& tokenType : semantic_tokens_legend.tokenTypes)
            tokenTypes.emplace_back(tokenType);
        object["tokenTypes"] = tokenTypes;
        nlohmann::json tokenModifiers = nlohmann::json::array();
        for(const std::string& tokenModifier : semantic_tokens_legend.tokenModifiers)
            tokenModifiers.emplace_back(tokenModifier);
        object["tokenModifiers"] = tokenModifiers;
    }
}

#endif