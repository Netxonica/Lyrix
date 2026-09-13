// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ExecuteCommandOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ExecuteCommandOptions& execute_command_options)
    noexcept -> void
    {
        from_json(object, static_cast<WorkDoneProgressOptions&>(execute_command_options));
        const nlohmann::json& commands = object.at("commands");
        for(const nlohmann::json& command : commands)
            execute_command_options.commands.emplace_back(command.get<std::string>());
    }

    auto to_json(nlohmann::json& object, const ExecuteCommandOptions& execute_command_options)
    noexcept -> void
    {
        to_json(object, static_cast<const WorkDoneProgressOptions&>(execute_command_options));
        nlohmann::json commands = nlohmann::json::array();
        for(const std::string& command : execute_command_options.commands)
            commands.emplace_back(command);
        object["commands"] = commands;
    }
}

#endif