// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/SignatureHelpClientCapabilities.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, SignatureHelpClientCapabilities&
    signature_help_client_capabilities) noexcept -> void
    {
        if(object.contains("dynamicRegistration"))
            signature_help_client_capabilities.dynamicRegistration = object.at(
            "dynamicRegistration").get<bool>();
        if(object.contains("signatureInformation"))
            signature_help_client_capabilities.signatureInformation = object.at(
            "signatureInformation").get<ClientSignatureInformationOptions>();
        if(object.contains("contextSupport"))
            signature_help_client_capabilities.contextSupport = object.at("contextSupport").get<
            bool>();
    }

    auto to_json(nlohmann::json& object, const SignatureHelpClientCapabilities&
    signature_help_client_capabilities) noexcept -> void
    {
        if(signature_help_client_capabilities.dynamicRegistration.has_value())
            object["dynamicRegistration"] = *signature_help_client_capabilities.dynamicRegistration
            ;
        if(signature_help_client_capabilities.signatureInformation.has_value())
            object["signatureInformation"] = *signature_help_client_capabilities.
            signatureInformation;
        if(signature_help_client_capabilities.contextSupport.has_value())
            object["contextSupport"] = *signature_help_client_capabilities.contextSupport;
    }
}

#endif