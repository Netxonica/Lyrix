// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_did_change_watched_files_params
#define lyrix_header_guard_eura_did_change_watched_files_params
#include "Eura/FileEvent.hpp"

namespace Eura
{
    struct [[nodiscard]] DidChangeWatchedFilesParams final
    {
        std::vector<FileEvent> changes;
    };

    auto from_json(const nlohmann::json& object, DidChangeWatchedFilesParams&
    did_change_watched_files_params) noexcept -> void;

    auto to_json(nlohmann::json& object, const DidChangeWatchedFilesParams&
    did_change_watched_files_params) noexcept -> void;
}

#endif
#endif