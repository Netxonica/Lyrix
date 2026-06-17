// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_response_error
#define lyrix_header_guard_eura_response_error
#include "Eura/Any.hpp"

namespace Eura
{
    struct [[nodiscard]] ResponseError final
    {
        Json::Integer code;

        Json::String message;

        std::optional<Json::Any> data;
    };

    auto Deserialize(Json::Object& object, ResponseError& response_error) noexcept -> void;

    auto Serialize(Json::Object& object, ResponseError& response_error) noexcept -> void;
}

#endif
#endif