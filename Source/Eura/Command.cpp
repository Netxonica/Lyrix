// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Command.hpp"

namespace Eura
{
    auto Deserialize(const Json::Object& object, Command& command) noexcept -> void
    {
        command.title = object.Retrieve("title").As<Json::String>();
        if(object.Contains("tooltip"))
            command.tooltip = object.Retrieve("tooltip").As<Json::String>();
        command.command = object.Retrieve("command").As<Json::String>();
        if(object.Contains("arguments"))
            command.arguments = std::move(object.Retrieve("arguments").As<std::vector<Json::Any>>()
            );
    }

    auto Serialize(Json::Object& object, const Command& command) noexcept -> void
    {
        object.fields.emplace_back("title", command.title);
        if(command.tooltip.has_value())
            object.fields.emplace_back("tooltip", *command.tooltip);
        object.fields.emplace_back("command", command.command);
        if(command.arguments.has_value())
            object.NestedArray("arguments") = *command.arguments;
    }
}

#endif