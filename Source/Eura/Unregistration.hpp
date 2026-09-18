// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_unregistration
#define lyrix_header_guard_eura_unregistration
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] Unregistration final
    {
        std::string id, method;
    };

    auto from_json(const nlohmann::json& object, Unregistration& unregistration) noexcept -> void;

    auto to_json(nlohmann::json& object, const Unregistration& unregistration) noexcept -> void;
}

#endif
#endif