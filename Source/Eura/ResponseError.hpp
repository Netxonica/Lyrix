// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_response_error
#define lyrix_header_guard_eura_response_error
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] ResponseError final
    {
        std::int32_t code;

        std::string message;

        std::optional<nlohmann::json> data;
    };

    auto from_json(const nlohmann::json& object, ResponseError& response_error) noexcept -> void;

    auto to_json(nlohmann::json& object, const ResponseError& response_error) noexcept -> void;
}

#endif
#endif