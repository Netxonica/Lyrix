// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ClientSemanticTokensRequestFullDelta.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ClientSemanticTokensRequestFullDelta&
    client_semantic_tokens_request_full_delta) noexcept -> void
    {
        if(object.contains("delta"))
            client_semantic_tokens_request_full_delta.delta = object.at("delta").get<bool>();
    }

    auto to_json(nlohmann::json& object, const ClientSemanticTokensRequestFullDelta&
    client_semantic_tokens_request_full_delta) noexcept -> void
    {
        if(client_semantic_tokens_request_full_delta.delta.has_value())
            object["delta"] = *client_semantic_tokens_request_full_delta.delta;
    }
}

#endif