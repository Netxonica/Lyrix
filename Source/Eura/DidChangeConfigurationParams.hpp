// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_did_change_configuration_params
#define lyrix_header_guard_eura_did_change_configuration_params
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] DidChangeConfigurationParams final
    {
        nlohmann::json settings;
    };

    auto from_json(const nlohmann::json& object, DidChangeConfigurationParams&
    did_change_configuration_params) noexcept -> void;

    auto to_json(nlohmann::json& object, const DidChangeConfigurationParams&
    did_change_configuration_params) noexcept -> void;
}

#endif
#endif