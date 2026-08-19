// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Command.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, Command& command) noexcept -> void
    {
        command.title = object.at("title").get<std::string>();
        if(object.contains("tooltip"))
            command.tooltip = object.at("tooltip").get<std::string>();
        command.command = object.at("command").get<std::string>();
        if(object.contains("arguments"))
            command.arguments = object.at("arguments");
    }

    auto to_json(nlohmann::json& object, const Command& command) noexcept -> void
    {
        object["title"] = command.title;
        if(command.tooltip.has_value())
            object["tooltip"] = *command.tooltip;
        object["command"] = command.command;
        if(command.arguments.has_value())
            object["arguments"] = *command.arguments;
    }
}

#endif