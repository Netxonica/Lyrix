// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_code_action_client_capabilities
#define lyrix_header_guard_eura_code_action_client_capabilities
#include "Eura/CodeActionTagOptions.hpp"
#include "Eura/ClientCodeActionLiteralOptions.hpp"
#include "Eura/ClientCodeActionResolveOptions.hpp"

namespace Eura
{
    struct [[nodiscard]] CodeActionClientCapabilities final
    {
        std::optional<bool> dynamicRegistration;

        std::optional<ClientCodeActionLiteralOptions> codeActionLiteralSupport;

        std::optional<bool> isPreferredSupport, disabledSupport, dataSupport;

        std::optional<ClientCodeActionResolveOptions> resolveSupport;

        std::optional<bool> honorsChangeAnnotations, documentationSupport;

        std::optional<CodeActionTagOptions> tagSupport;
    };

    auto from_json(const nlohmann::json& object, CodeActionClientCapabilities&
    code_action_client_capabilities) noexcept -> void;

    auto to_json(nlohmann::json& object, const CodeActionClientCapabilities&
    code_action_client_capabilities) noexcept -> void;
}

#endif
#endif