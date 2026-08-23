// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ClientSemanticTokensRequestOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ClientSemanticTokensRequestOptions&
    client_semantic_tokens_request_options) noexcept -> void
    {
        if(object.contains("range"))
        {
            const nlohmann::json& range = object.at("range");
            if(range.is_boolean())
                client_semantic_tokens_request_options.range = range.get<bool>();
            else
                client_semantic_tokens_request_options.range = range.get<Empty>();
        }
        if(object.contains("full"))
        {
            const nlohmann::json& full = object.at("full");
            if(full.is_boolean())
                client_semantic_tokens_request_options.full = full.get<bool>();
            else
                client_semantic_tokens_request_options.full = full.get<
                ClientSemanticTokensRequestFullDelta>();
        }
    }

    auto to_json(nlohmann::json& object, const ClientSemanticTokensRequestOptions&
    client_semantic_tokens_request_options) noexcept -> void
    {
        if(client_semantic_tokens_request_options.range.has_value())
            std::visit([&object](auto&& range)
            {
                object["range"] = range;
            }, *client_semantic_tokens_request_options.range);
        if(client_semantic_tokens_request_options.full.has_value())
            std::visit([&object](auto&& full)
            {
                object["full"] = full;
            }, *client_semantic_tokens_request_options.full);
    }
}

#endif