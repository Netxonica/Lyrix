// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/SignatureInformation.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, SignatureInformation& signature_information)
    noexcept -> void
    {
        signature_information.label = object.at("label").get<std::string>();
        if(object.contains("documentation"))
        {
            const nlohmann::json& documentation = object.at("documentation");
            if(documentation.is_string())
                signature_information.documentation = documentation.get<std::string>();
            else
                signature_information.documentation = documentation.get<MarkupContent>();
        }
        if(object.contains("parameters"))
        {
            signature_information.parameters = std::vector<ParameterInformation>{};
            const nlohmann::json& parameters = object.at("parameters");
            for(const nlohmann::json& parameter : parameters)
                signature_information.parameters->emplace_back(parameter.get<ParameterInformation>(
                ));
        }
        if(object.contains("activeParameter"))
        {
            const nlohmann::json& activeParameter = object.at("activeParameter");
            if(activeParameter.is_number_unsigned())
                signature_information.activeParameter = activeParameter.get<std::uint32_t>();
            else
                signature_information.activeParameter = nullptr;
        }
    }

    auto to_json(nlohmann::json& object, const SignatureInformation& signature_information)
    noexcept -> void
    {
        object["label"] = signature_information.label;
        if(signature_information.documentation.has_value())
            std::visit([&object](auto&& documentation)
            {
                object["documentation"] = documentation;
            }, *signature_information.documentation);
        if(signature_information.parameters.has_value())
        {
            nlohmann::json parameters = nlohmann::json::array();
            for(const ParameterInformation& parameter : *signature_information.parameters)
                parameters.emplace_back(parameter);
            object["parameters"] = parameters;
        }
        if(signature_information.activeParameter.has_value())
            std::visit([&object](auto&& activeParameter)
            {
                object["activeParameter"] = activeParameter;
            }, *signature_information.activeParameter);
    }
}

#endif