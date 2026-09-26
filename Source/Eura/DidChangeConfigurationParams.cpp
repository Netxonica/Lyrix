// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DidChangeConfigurationParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DidChangeConfigurationParams&
    did_change_configuration_params) noexcept -> void
    {
        did_change_configuration_params.settings = object.at("settings");
    }

    auto to_json(nlohmann::json& object, const DidChangeConfigurationParams&
    did_change_configuration_params) noexcept -> void
    {
        object["settings"] = did_change_configuration_params.settings;
    }
}

#endif