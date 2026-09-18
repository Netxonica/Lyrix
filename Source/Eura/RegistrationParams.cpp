// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/RegistrationParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, RegistrationParams& registration_params) noexcept
    -> void
    {
        const nlohmann::json& registrations = object.at("registrations");
        for(const nlohmann::json& registration : registrations)
            registration_params.registrations.emplace_back(registration.get<Registration>());
    }

    auto to_json(nlohmann::json& object, const RegistrationParams& registration_params) noexcept ->
    void
    {
        nlohmann::json registrations = nlohmann::json::array();
        for(const Registration& registration : registration_params.registrations)
            registrations.emplace_back(registration);
        object["registrations"] = registrations;
    }
}

#endif