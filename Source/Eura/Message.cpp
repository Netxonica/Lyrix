// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Message.hpp"

namespace Eura
{
    auto Deserialize(const Json::Object& object, Message& message) noexcept -> void
    {
        message.jsonrpc = object.Retrieve("jsonrpc").As<Json::String>();
    }

    auto Serialize(Json::Object& object, const Message& message) noexcept -> void
    {
        object.fields.emplace_back("jsonrpc", message.jsonrpc);
    }
}

#endif