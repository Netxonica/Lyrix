// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_did_change_watched_files_registration_options
#define lyrix_header_guard_eura_did_change_watched_files_registration_options
#include "Eura/FileSystemWatcher.hpp"

namespace Eura
{
    struct [[nodiscard]] DidChangeWatchedFilesRegistrationOptions final
    {
        std::vector<FileSystemWatcher> watchers;
    };

    auto from_json(const nlohmann::json& object, DidChangeWatchedFilesRegistrationOptions&
    did_change_watched_files_registration_options) noexcept -> void;

    auto to_json(nlohmann::json& object, const DidChangeWatchedFilesRegistrationOptions&
    did_change_watched_files_registration_options) noexcept -> void;
}

#endif
#endif