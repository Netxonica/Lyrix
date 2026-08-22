// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ClientSignatureParameterInformationOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ClientSignatureParameterInformationOptions&
    client_signature_parameter_information_options) noexcept -> void
    {
        if(object.contains("labelOffsetSupport"))
            client_signature_parameter_information_options.labelOffsetSupport = object.at(
            "labelOffsetSupport").get<bool>();
    }

    auto to_json(nlohmann::json& object, const ClientSignatureParameterInformationOptions&
    client_signature_parameter_information_options) noexcept -> void
    {
        if(client_signature_parameter_information_options.labelOffsetSupport.has_value())
            object["labelOffsetSupport"] = *client_signature_parameter_information_options.
            labelOffsetSupport;
    }
}

#endif