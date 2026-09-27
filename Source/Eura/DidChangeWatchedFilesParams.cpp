// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DidChangeWatchedFilesParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DidChangeWatchedFilesParams&
    did_change_watched_files_params) noexcept -> void
    {
        const nlohmann::json& changes = object.at("changes");
        for(const nlohmann::json& change : changes)
            did_change_watched_files_params.changes.emplace_back(change.get<FileEvent>());
    }

    auto to_json(nlohmann::json& object, const DidChangeWatchedFilesParams&
    did_change_watched_files_params) noexcept -> void
    {
        nlohmann::json changes = nlohmann::json::array();
        for(const FileEvent& change : did_change_watched_files_params.changes)
            changes.emplace_back(change);
        object["changes"] = changes;
    }
}

#endif