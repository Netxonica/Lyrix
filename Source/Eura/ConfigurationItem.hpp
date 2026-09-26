// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_configuration_item
#define lyrix_header_guard_eura_configuration_item
#include "Eura/URI.hpp"
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] ConfigurationItem final
    {
        std::optional<URI> scopeUri;

        std::optional<std::string> section;
    };

    auto from_json(const nlohmann::json& object, ConfigurationItem& configuration_item) noexcept ->
    void;

    auto to_json(nlohmann::json& object, const ConfigurationItem& configuration_item) noexcept ->
    void;
}

#endif
#endif