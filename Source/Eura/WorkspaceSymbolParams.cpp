// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/WorkspaceSymbolParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, WorkspaceSymbolParams& workspace_symbol_params)
    noexcept -> void
    {
        from_json(object, static_cast<WorkDoneProgressParams&>(workspace_symbol_params));
        from_json(object, static_cast<PartialResultParams&>(workspace_symbol_params));
        workspace_symbol_params.query = object.at("query").get<std::string>();
    }

    auto to_json(nlohmann::json& object, const WorkspaceSymbolParams& workspace_symbol_params)
    noexcept -> void
    {
        to_json(object, static_cast<const WorkDoneProgressParams&>(workspace_symbol_params));
        to_json(object, static_cast<const PartialResultParams&>(workspace_symbol_params));
        object["query"] = workspace_symbol_params.query;
    }
}

#endif