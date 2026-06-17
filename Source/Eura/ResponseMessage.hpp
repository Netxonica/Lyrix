// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_response_message
#define lyrix_header_guard_eura_response_message
#include "Eura/Message.hpp"
#include "Eura/ResponseError.hpp"

namespace Eura
{
    struct [[nodiscard]] ResponseMessage final : public Message
    {
        std::variant<Json::Integer, Json::String, Json::Null> id;

        std::optional<Json::Any> result;

        std::optional<ResponseError> error;
    };

    auto Deserialize(Json::Object& object, ResponseMessage& response_message) noexcept -> void;

    auto Serialize(Json::Object& object, ResponseMessage& response_message) noexcept -> void;
}

#endif
#endif