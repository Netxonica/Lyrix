// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_message
#define lyrix_header_guard_eura_message
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] Message
    {
        std::string jsonrpc;
    };

    auto from_json(const nlohmann::json& object, Message& message) noexcept -> void;

    auto to_json(nlohmann::json& object, const Message& message) noexcept -> void;
}

#endif
#endif