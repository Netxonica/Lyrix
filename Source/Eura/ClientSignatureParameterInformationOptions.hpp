// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_client_signature_parameter_information_options
#define lyrix_header_guard_eura_client_signature_parameter_information_options
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] ClientSignatureParameterInformationOptions final
    {
        std::optional<bool> labelOffsetSupport;
    };

    auto from_json(const nlohmann::json& object, ClientSignatureParameterInformationOptions&
    client_signature_parameter_information_options) noexcept -> void;

    auto to_json(nlohmann::json& object, const ClientSignatureParameterInformationOptions&
    client_signature_parameter_information_options) noexcept -> void;
}

#endif
#endif