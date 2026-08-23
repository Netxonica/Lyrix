// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_code_lens_client_capabilities
#define lyrix_header_guard_eura_code_lens_client_capabilities
#include "Eura/ClientCodeLensResolveOptions.hpp"

namespace Eura
{
    struct [[nodiscard]] CodeLensClientCapabilities final
    {
        std::optional<bool> dynamicRegistration;

        std::optional<ClientCodeLensResolveOptions> resolveSupport;
    };

    auto from_json(const nlohmann::json& object, CodeLensClientCapabilities&
    code_lens_client_capabilities) noexcept -> void;

    auto to_json(nlohmann::json& object, const CodeLensClientCapabilities&
    code_lens_client_capabilities) noexcept -> void;
}

#endif
#endif