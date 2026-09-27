// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DidChangeWatchedFilesRegistrationOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DidChangeWatchedFilesRegistrationOptions&
    did_change_watched_files_registration_options) noexcept -> void
    {
        const nlohmann::json& watchers = object.at("watchers");
        for(const nlohmann::json& watcher : watchers)
            did_change_watched_files_registration_options.watchers.emplace_back(watcher.get<
            FileSystemWatcher>());
    }

    auto to_json(nlohmann::json& object, const DidChangeWatchedFilesRegistrationOptions&
    did_change_watched_files_registration_options) noexcept -> void
    {
        nlohmann::json watchers = nlohmann::json::array();
        for(const FileSystemWatcher& watcher : did_change_watched_files_registration_options.
        watchers)
            watchers.emplace_back(watcher);
        object["watchers"] = watchers;
    }
}

#endif