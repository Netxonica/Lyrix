// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/FileSystemWatcher.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, FileSystemWatcher& file_system_watcher) noexcept
    -> void
    {
        const nlohmann::json& globPattern = object.at("globPattern");
        if(globPattern.is_string())
            file_system_watcher.globPattern = globPattern.get<Pattern>();
        else
            file_system_watcher.globPattern = globPattern.get<RelativePattern>();
        if(object.contains("kind"))
            file_system_watcher.kind = object.at("kind").get<WatchKind>();
    }

    auto to_json(nlohmann::json& object, const FileSystemWatcher& file_system_watcher) noexcept ->
    void
    {
        std::visit([&object](auto&& globPattern)
        {
            object["globPattern"] = globPattern;
        }, file_system_watcher.globPattern);
        if(file_system_watcher.kind.has_value())
            object["kind"] = *file_system_watcher.kind;
    }
}

#endif