// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_workspace_folders_server_capabilities
#define lyrix_header_guard_eura_workspace_folders_server_capabilities
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] WorkspaceFoldersServerCapabilities final
    {
        std::optional<bool> supported;

        std::optional<std::variant<std::string, bool>> changeNotifications;
    };

    auto from_json(const nlohmann::json& object, WorkspaceFoldersServerCapabilities&
    workspace_folders_server_capabilities) noexcept -> void;

    auto to_json(nlohmann::json& object, const WorkspaceFoldersServerCapabilities&
    workspace_folders_server_capabilities) noexcept -> void;
}

#endif
#endif