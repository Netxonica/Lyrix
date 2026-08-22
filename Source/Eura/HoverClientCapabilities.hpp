// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_hover_client_capabilities
#define lyrix_header_guard_eura_hover_client_capabilities
#include "Eura/Json.hpp"
#include "Eura/MarkupKind.hpp"

namespace Eura
{
    struct [[nodiscard]] HoverClientCapabilities final
    {
        std::optional<bool> dynamicRegistration;

        std::optional<std::vector<MarkupKind>> contentFormat;
    };

    auto from_json(const nlohmann::json& object, HoverClientCapabilities& hover_client_capabilities
    ) noexcept -> void;

    auto to_json(nlohmann::json& object, const HoverClientCapabilities& hover_client_capabilities)
    noexcept -> void;
}

#endif
#endif