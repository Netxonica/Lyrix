// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_static_registration_options
#define lyrix_header_guard_eura_static_registration_options
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] StaticRegistrationOptions
    {
        std::optional<std::string> id;
    };

    auto from_json(const nlohmann::json& object, StaticRegistrationOptions&
    static_registration_options) noexcept -> void;

    auto to_json(nlohmann::json& object, const StaticRegistrationOptions&
    static_registration_options) noexcept -> void;
}

#endif
#endif