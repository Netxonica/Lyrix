// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ParameterInformation.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ParameterInformation& parameter_information)
    noexcept -> void
    {
        const nlohmann::json& label = object.at("label");
        if(label.is_string())
            parameter_information.label = label.get<std::string>();
        else
            parameter_information.label = label.get<std::array<std::uint32_t, 2uz>>();
        if(object.contains("documentation"))
        {
            const nlohmann::json& documentation = object.at("documentation");
            if(documentation.is_string())
                parameter_information.documentation = documentation.get<std::string>();
            else
                parameter_information.documentation = documentation.get<MarkupContent>();
        }
    }

    auto to_json(nlohmann::json& object, const ParameterInformation& parameter_information)
    noexcept -> void
    {
        if(std::holds_alternative<std::string>(parameter_information.label))
            object["label"] = std::get<std::string>(parameter_information.label);
        else
        {
            nlohmann::json label = nlohmann::json::array();
            const std::array<std::uint32_t, 2uz> labels = std::get<std::array<std::uint32_t, 2uz>>(
            parameter_information.label);
            for(const std::uint32_t labe : labels)
                label.emplace_back(labe);
            object["label"] = label;
        }
        if(parameter_information.documentation.has_value())
            std::visit([&object](auto&& documentation)
            {
                object["documentation"] = documentation;
            }, *parameter_information.documentation);
    }
}

#endif