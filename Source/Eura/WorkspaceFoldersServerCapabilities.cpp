// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/WorkspaceFoldersServerCapabilities.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, WorkspaceFoldersServerCapabilities&
    workspace_folders_server_capabilities) noexcept -> void
    {
        if(object.contains("supported"))
            workspace_folders_server_capabilities.supported = object.at("supported").get<bool>();
        if(object.contains("changeNotifications"))
        {
            const nlohmann::json& changeNotifications = object.at("changeNotifications");
            if(changeNotifications.is_string())
                workspace_folders_server_capabilities.changeNotifications = changeNotifications.get
                <std::string>();
            else
                workspace_folders_server_capabilities.changeNotifications = changeNotifications.get
                <bool>();
        }
    }

    auto to_json(nlohmann::json& object, const WorkspaceFoldersServerCapabilities&
    workspace_folders_server_capabilities) noexcept -> void
    {
        if(workspace_folders_server_capabilities.supported.has_value())
            object["supported"] = *workspace_folders_server_capabilities.supported;
        if(workspace_folders_server_capabilities.changeNotifications.has_value())
            std::visit([&object](auto&& changeNotifications)
            {
                object["changeNotifications"] = changeNotifications;
            }, *workspace_folders_server_capabilities.changeNotifications);
    }
}

#endif