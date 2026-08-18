// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_request_message
#define lyrix_header_guard_eura_request_message
#include "Eura/Message.hpp"

namespace Eura
{
    struct [[nodiscard]] RequestMessage final : Message
    {
        std::variant<std::int32_t, std::string> id;
    };

    auto from_json(const nlohmann::json& object, RequestMessage& request_message) noexcept -> void;

    auto to_json(nlohmann::json& object, const RequestMessage& request_message) noexcept -> void;
}

#endif
#endif