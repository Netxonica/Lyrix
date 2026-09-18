// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_unregistration_params
#define lyrix_header_guard_eura_unregistration_params
#include "Eura/Unregistration.hpp"

namespace Eura
{
    struct [[nodiscard]] UnregistrationParams final
    {
        std::vector<Unregistration> unregistrations;
    };

    auto from_json(const nlohmann::json& object, UnregistrationParams& unregistration_params)
    noexcept -> void;

    auto to_json(nlohmann::json& object, const UnregistrationParams& unregistration_params)
    noexcept -> void;
}

#endif
#endif