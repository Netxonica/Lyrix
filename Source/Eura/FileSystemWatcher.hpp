// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_file_system_watcher
#define lyrix_header_guard_eura_file_system_watcher
#include "Eura/WatchKind.hpp"
#include "Eura/GlobPattern.hpp"

namespace Eura
{
    struct [[nodiscard]] FileSystemWatcher final
    {
        GlobPattern globPattern;

        std::optional<WatchKind> kind;
    };

    auto from_json(const nlohmann::json& object, FileSystemWatcher& file_system_watcher) noexcept
    -> void;

    auto to_json(nlohmann::json& object, const FileSystemWatcher& file_system_watcher) noexcept ->
    void;
}

#endif
#endif