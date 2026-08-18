// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_cancel_params
#define lyrix_header_guard_eura_cancel_params
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] CancelParams final
    {
        std::variant<std::int32_t, std::string> id;
    };

    auto from_json(const nlohmann::json& object, CancelParams& cancel_params) noexcept -> void;

    auto to_json(nlohmann::json& object, const CancelParams& cancel_params) noexcept -> void;
}

#endif
#endif