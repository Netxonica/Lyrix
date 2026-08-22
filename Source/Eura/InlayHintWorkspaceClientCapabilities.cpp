// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/InlayHintWorkspaceClientCapabilities.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, InlayHintWorkspaceClientCapabilities&
    inlay_hint_workspace_client_capabilities) noexcept -> void
    {
        if(object.contains("refreshSupport"))
            inlay_hint_workspace_client_capabilities.refreshSupport = object.at("refreshSupport").
            get<bool>();
    }

    auto to_json(nlohmann::json& object, const InlayHintWorkspaceClientCapabilities&
    inlay_hint_workspace_client_capabilities) noexcept -> void
    {
        if(inlay_hint_workspace_client_capabilities.refreshSupport.has_value())
            object["refreshSupport"] = *inlay_hint_workspace_client_capabilities.refreshSupport;
    }
}

#endif