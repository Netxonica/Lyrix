// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/UnregistrationParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, UnregistrationParams& unregistration_params)
    noexcept -> void
    {
        const nlohmann::json& unregistrations = object.at("unregistrations");
        for(const nlohmann::json& unregistration : unregistrations)
            unregistration_params.unregistrations.emplace_back(unregistration.get<Unregistration>()
            );
    }

    auto to_json(nlohmann::json& object, const UnregistrationParams& unregistration_params)
    noexcept -> void
    {
        nlohmann::json unregistrations = nlohmann::json::array();
        for(const Unregistration& unregistration : unregistration_params.unregistrations)
            unregistrations.emplace_back(unregistration);
        object["unregistrations"] = unregistrations;
    }
}

#endif