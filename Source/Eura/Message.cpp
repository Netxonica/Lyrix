// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Message.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, Message& message) noexcept -> void
    {
        message.jsonrpc = object.at("jsonrpc").get<std::string>();
    }

    auto to_json(nlohmann::json& object, const Message& message) noexcept -> void
    {
        object["jsonrpc"] = message.jsonrpc;
    }
}

#endif