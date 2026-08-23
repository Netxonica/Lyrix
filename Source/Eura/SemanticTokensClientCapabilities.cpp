// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/SemanticTokensClientCapabilities.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, SemanticTokensClientCapabilities&
    semantic_tokens_client_capabilities) noexcept -> void
    {
        if(object.contains("dynamicRegistration"))
            semantic_tokens_client_capabilities.dynamicRegistration = object.at(
            "dynamicRegistration").get<bool>();
        semantic_tokens_client_capabilities.requests = object.at("requests").get<
        ClientSemanticTokensRequestOptions>();
        const nlohmann::json& tokenTypes = object.at("tokenTypes");
        for(const nlohmann::json& tokenType : tokenTypes)
            semantic_tokens_client_capabilities.tokenTypes.emplace_back(tokenType.get<std::string>(
            ));
        const nlohmann::json& tokenModifiers = object.at("tokenModifiers");
        for(const nlohmann::json& tokenModifier : tokenModifiers)
            semantic_tokens_client_capabilities.tokenModifiers.emplace_back(tokenModifier.get<std::
            string>());
        const nlohmann::json& formats = object.at("formats");
        for(const nlohmann::json& format : formats)
            semantic_tokens_client_capabilities.formats.emplace_back(format.get<TokenFormat>());
        if(object.contains("overlappingTokenSupport"))
            semantic_tokens_client_capabilities.overlappingTokenSupport = object.at(
            "overlappingTokenSupport").get<bool>();
        if(object.contains("multilineTokenSupport"))
            semantic_tokens_client_capabilities.multilineTokenSupport = object.at(
            "multilineTokenSupport").get<bool>();
        if(object.contains("serverCancelSupport"))
            semantic_tokens_client_capabilities.serverCancelSupport = object.at(
            "serverCancelSupport").get<bool>();
        if(object.contains("augmentsSyntaxTokens"))
            semantic_tokens_client_capabilities.augmentsSyntaxTokens = object.at(
            "augmentsSyntaxTokens").get<bool>();
    }

    auto to_json(nlohmann::json& object, const SemanticTokensClientCapabilities&
    semantic_tokens_client_capabilities) noexcept -> void
    {
        if(semantic_tokens_client_capabilities.dynamicRegistration.has_value())
            object["dynamicRegistration"] = *semantic_tokens_client_capabilities.
            dynamicRegistration;
        object["requests"] = semantic_tokens_client_capabilities.requests;
        nlohmann::json tokenTypes = nlohmann::json::array();
        for(const std::string& tokenType : semantic_tokens_client_capabilities.tokenTypes)
            tokenTypes.emplace_back(tokenType);
        object["tokenTypes"] = tokenTypes;
        nlohmann::json tokenModifiers = nlohmann::json::array();
        for(const std::string& tokenModifier : semantic_tokens_client_capabilities.tokenModifiers)
            tokenModifiers.emplace_back(tokenModifier);
        object["tokenModifiers"] = tokenModifiers;
        nlohmann::json formats = nlohmann::json::array();
        for(const TokenFormat& format : semantic_tokens_client_capabilities.formats)
            formats.emplace_back(format);
        object["formats"] = formats;
        if(semantic_tokens_client_capabilities.overlappingTokenSupport.has_value())
            object["overlappingTokenSupport"] = *semantic_tokens_client_capabilities.
            overlappingTokenSupport;
        if(semantic_tokens_client_capabilities.multilineTokenSupport.has_value())
            object["multilineTokenSupport"] = *semantic_tokens_client_capabilities.
            multilineTokenSupport;
        if(semantic_tokens_client_capabilities.serverCancelSupport.has_value())
            object["serverCancelSupport"] = *semantic_tokens_client_capabilities.
            serverCancelSupport;
        if(semantic_tokens_client_capabilities.augmentsSyntaxTokens.has_value())
            object["augmentsSyntaxTokens"] = *semantic_tokens_client_capabilities.
            augmentsSyntaxTokens;
    }
}

#endif