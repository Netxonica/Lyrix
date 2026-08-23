// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_client_code_action_resolve_options
#define lyrix_header_guard_eura_client_code_action_resolve_options
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] ClientCodeActionResolveOptions final
    {
        std::vector<std::string> properties;
    };

    auto from_json(const nlohmann::json& object, ClientCodeActionResolveOptions&
    client_code_action_resolve_options) noexcept -> void;

    auto to_json(nlohmann::json& object, const ClientCodeActionResolveOptions&
    client_code_action_resolve_options) noexcept -> void;
}

#endif
#endif