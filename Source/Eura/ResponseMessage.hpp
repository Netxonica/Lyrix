// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_response_message
#define lyrix_header_guard_eura_response_message
#include "Eura/Message.hpp"
#include "Eura/ResponseError.hpp"

namespace Eura
{
    struct [[nodiscard]] ResponseMessage final : Message
    {
        std::variant<std::int32_t, std::string, std::nullptr_t> id;
        
        std::optional<nlohmann::json> result;

        std::optional<ResponseError> error;
    };

    auto from_json(const nlohmann::json& object, ResponseMessage& response_message) noexcept ->
    void;

    auto to_json(nlohmann::json& object, const ResponseMessage& response_message) noexcept -> void;
}

#endif
#endif