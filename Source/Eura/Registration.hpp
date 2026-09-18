// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_registration
#define lyrix_header_guard_eura_registration
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] Registration final
    {
        std::string id, method;

        std::optional<nlohmann::json> registerOptions;
    };

    auto from_json(const nlohmann::json& object, Registration& registration) noexcept -> void;

    auto to_json(nlohmann::json& object, const Registration& registration) noexcept -> void;
}

#endif
#endif