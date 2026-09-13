// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/WorkspaceSymbolOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, WorkspaceSymbolOptions& workspace_symbol_options)
    noexcept -> void
    {
        from_json(object, static_cast<WorkDoneProgressOptions&>(workspace_symbol_options));
        if(object.contains("resolveProvider"))
            workspace_symbol_options.resolveProvider = object.at("resolveProvider").get<bool>();
    }

    auto to_json(nlohmann::json& object, const WorkspaceSymbolOptions& workspace_symbol_options)
    noexcept -> void
    {
        to_json(object, static_cast<const WorkDoneProgressOptions&>(workspace_symbol_options));
        if(workspace_symbol_options.resolveProvider.has_value())
            object["resolveProvider"] = *workspace_symbol_options.resolveProvider;
    }
}

#endif