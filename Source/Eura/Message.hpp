// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_message
#define lyrix_header_guard_eura_message
#include "Eura/Any.hpp"

namespace Eura
{
    struct [[nodiscard]] Message
    {
        Json::String jsonrpc;
    };

    auto Deserialize(const Json::Object& object, Message& message) noexcept -> void;

    auto Serialize(Json::Object& object, const Message& message) noexcept -> void;
}

#endif
#endif