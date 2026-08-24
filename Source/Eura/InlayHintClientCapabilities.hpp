// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_inlay_hint_client_capabilities
#define lyrix_header_guard_eura_inlay_hint_client_capabilities
#include "Eura/ClientInlayHintResolveOptions.hpp"

namespace Eura
{
    struct [[nodiscard]] InlayHintClientCapabilities final
    {
        std::optional<bool> dynamicRegistration;

        std::optional<ClientInlayHintResolveOptions> resolveSupport;
    };

    auto from_json(const nlohmann::json& object, InlayHintClientCapabilities&
    inlay_hint_client_capabilities) noexcept -> void;

    auto to_json(nlohmann::json& object, const InlayHintClientCapabilities&
    inlay_hint_client_capabilities) noexcept -> void;
}

#endif
#endif