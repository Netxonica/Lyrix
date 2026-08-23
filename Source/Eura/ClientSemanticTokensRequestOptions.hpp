// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_client_semantic_tokens_request_options
#define lyrix_header_guard_eura_client_semantic_tokens_request_options
#include "Eura/Empty.hpp"
#include "Eura/ClientSemanticTokensRequestFullDelta.hpp"

namespace Eura
{
    struct [[nodiscard]] ClientSemanticTokensRequestOptions final
    {
        std::optional<std::variant<bool, Empty>> range;

        std::optional<std::variant<bool, ClientSemanticTokensRequestFullDelta>> full;
    };

    auto from_json(const nlohmann::json& object, ClientSemanticTokensRequestOptions&
    client_semantic_tokens_request_options) noexcept -> void;

    auto to_json(nlohmann::json& object, const ClientSemanticTokensRequestOptions&
    client_semantic_tokens_request_options) noexcept -> void;
}

#endif
#endif