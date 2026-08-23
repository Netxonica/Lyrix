// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_semantic_tokens_client_capabilities
#define lyrix_header_guard_eura_semantic_tokens_client_capabilities
#include "Eura/TokenFormat.hpp"
#include "Eura/ClientSemanticTokensRequestOptions.hpp"

namespace Eura
{
    struct [[nodiscard]] SemanticTokensClientCapabilities final
    {
        std::optional<bool> dynamicRegistration;

        ClientSemanticTokensRequestOptions requests;

        std::vector<std::string> tokenTypes, tokenModifiers;

        std::vector<TokenFormat> formats;

        std::optional<bool> overlappingTokenSupport, multilineTokenSupport, serverCancelSupport,
        augmentsSyntaxTokens;
    };

    auto from_json(const nlohmann::json& object, SemanticTokensClientCapabilities&
    semantic_tokens_client_capabilities) noexcept -> void;

    auto to_json(nlohmann::json& object, const SemanticTokensClientCapabilities&
    semantic_tokens_client_capabilities) noexcept -> void;
}

#endif
#endif