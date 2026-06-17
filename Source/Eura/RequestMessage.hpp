// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_request_message
#define lyrix_header_guard_eura_request_message
#include "Eura/Message.hpp"

namespace Eura
{
    struct [[nodiscard]] RequestMessage final : public Message
    {
        std::variant<Json::Integer, Json::String> id;

        Json::String method;

        std::optional<std::variant<Json::Array, Json::Object>> params;
    };

    auto Deserialize(Json::Object& object, RequestMessage& request_message) noexcept -> void;

    auto Serialize(Json::Object& object, RequestMessage& request_message) noexcept -> void;
}

#endif
#endif