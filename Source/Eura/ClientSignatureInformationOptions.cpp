// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ClientSignatureInformationOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ClientSignatureInformationOptions&
    client_signature_information_options) noexcept -> void
    {
        if(object.contains("documentationFormat"))
        {
            client_signature_information_options.documentationFormat = std::vector<MarkupKind>{};
            const nlohmann::json& documentationFormat = object.at("documentationFormat");
            for(const nlohmann::json& documentation : documentationFormat)
                client_signature_information_options.documentationFormat->emplace_back(
                documentation.get<MarkupKind>());
        }
        if(object.contains("parameterInformation"))
            client_signature_information_options.parameterInformation = object.at(
            "parameterInformation").get<ClientSignatureParameterInformationOptions>();
        if(object.contains("activeParameterSupport"))
            client_signature_information_options.activeParameterSupport = object.at(
            "activeParameterSupport").get<bool>();
        if(object.contains("noActiveParameterSupport"))
            client_signature_information_options.noActiveParameterSupport = object.at(
            "noActiveParameterSupport").get<bool>();
    }

    auto to_json(nlohmann::json& object, const ClientSignatureInformationOptions&
    client_signature_information_options) noexcept -> void
    {
        if(client_signature_information_options.documentationFormat.has_value())
        {
            nlohmann::json documentationFormat = nlohmann::json::array();
            for(const MarkupKind& documentation : *client_signature_information_options.
            documentationFormat)
                documentationFormat.emplace_back(documentation);
            object["documentationFormat"] = documentationFormat;
        }
        if(client_signature_information_options.parameterInformation.has_value())
            object["parameterInformation"] = *client_signature_information_options.
            parameterInformation;
        if(client_signature_information_options.activeParameterSupport.has_value())
            object["activeParameterSupport"] = *client_signature_information_options.
            activeParameterSupport;
        if(client_signature_information_options.noActiveParameterSupport.has_value())
            object["noActiveParameterSupport"] = *client_signature_information_options.
            noActiveParameterSupport;
    }
}

#endif