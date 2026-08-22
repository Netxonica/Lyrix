// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_client_signature_information_options
#define lyrix_header_guard_eura_client_signature_information_options
#include "Eura/MarkupKind.hpp"
#include "Eura/ClientSignatureParameterInformationOptions.hpp"

namespace Eura
{
    struct [[nodiscard]] ClientSignatureInformationOptions final
    {
        std::optional<std::vector<MarkupKind>> documentationFormat;

        std::optional<ClientSignatureParameterInformationOptions> parameterInformation;

        std::optional<bool> activeParameterSupport, noActiveParameterSupport;
    };

    auto from_json(const nlohmann::json& object, ClientSignatureInformationOptions&
    client_signature_information_options) noexcept -> void;

    auto to_json(nlohmann::json& object, const ClientSignatureInformationOptions&
    client_signature_information_options) noexcept -> void;
}

#endif
#endif