// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_signature_help_client_capabilities
#define lyrix_header_guard_eura_signature_help_client_capabilities
#include "Eura/ClientSignatureInformationOptions.hpp"

namespace Eura
{
    struct [[nodiscard]] SignatureHelpClientCapabilities final
    {
        std::optional<bool> dynamicRegistration;

        std::optional<ClientSignatureInformationOptions> signatureInformation;

        std::optional<bool> contextSupport;
    };

    auto from_json(const nlohmann::json& object, SignatureHelpClientCapabilities&
    signature_help_client_capabilities) noexcept -> void;

    auto to_json(nlohmann::json& object, const SignatureHelpClientCapabilities&
    signature_help_client_capabilities) noexcept -> void;
}

#endif
#endif