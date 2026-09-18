// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_registration_params
#define lyrix_header_guard_eura_registration_params
#include "Eura/Registration.hpp"

namespace Eura
{
    struct [[nodiscard]] RegistrationParams final
    {
        std::vector<Registration> registrations;
    };

    auto from_json(const nlohmann::json& object, RegistrationParams& registration_params) noexcept
    -> void;

    auto to_json(nlohmann::json& object, const RegistrationParams& registration_params) noexcept ->
    void;
}

#endif
#endif