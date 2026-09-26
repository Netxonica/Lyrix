// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_configuration_params
#define lyrix_header_guard_eura_configuration_params
#include "Eura/ConfigurationItem.hpp"

namespace Eura
{
    struct [[nodiscard]] ConfigurationParams final
    {
        std::vector<ConfigurationItem> items;
    };

    auto from_json(const nlohmann::json& object, ConfigurationParams& configuration_params)
    noexcept -> void;

    auto to_json(nlohmann::json& object, const ConfigurationParams& configuration_params) noexcept
    -> void;
}

#endif
#endif