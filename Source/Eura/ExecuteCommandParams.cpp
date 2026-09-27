// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ExecuteCommandParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ExecuteCommandParams& execute_command_params)
    noexcept -> void
    {
        from_json(object, static_cast<WorkDoneProgressParams&>(execute_command_params));
        execute_command_params.command = object.at("command").get<std::string>();
        if(object.contains("arguments"))
        {
            execute_command_params.arguments = std::vector<nlohmann::json>{};
            const nlohmann::json& arguments = object.at("arguments");
            for(const nlohmann::json& argument : arguments)
                execute_command_params.arguments->emplace_back(argument);
        }
    }

    auto to_json(nlohmann::json& object, const ExecuteCommandParams& execute_command_params)
    noexcept -> void
    {
        to_json(object, static_cast<const WorkDoneProgressParams&>(execute_command_params));
        object["command"] = execute_command_params.command;
        if(execute_command_params.arguments.has_value())
        {
            nlohmann::json arguments = nlohmann::json::array();
            for(const nlohmann::json& argument : *execute_command_params.arguments)
                arguments.emplace_back(argument);
            object["arguments"] = arguments;
        }
    }
}

#endif