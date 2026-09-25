// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/WorkspaceDiagnosticParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, WorkspaceDiagnosticParams&
    workspace_diagnostic_params) noexcept -> void
    {
        from_json(object, static_cast<WorkDoneProgressParams&>(workspace_diagnostic_params));
        from_json(object, static_cast<PartialResultParams&>(workspace_diagnostic_params));
        if(object.contains("identifier"))
            workspace_diagnostic_params.identifier = object.at("identifier").get<std::string>();
        const nlohmann::json& previousResultIds = object.at("previousResultIds");
        for(const nlohmann::json& previousResultId : previousResultIds)
            workspace_diagnostic_params.previousResultIds.emplace_back(previousResultId.get<
            PreviousResultId>());
    }

    auto to_json(nlohmann::json& object, const WorkspaceDiagnosticParams&
    workspace_diagnostic_params) noexcept -> void
    {
        to_json(object, static_cast<const WorkDoneProgressParams&>(workspace_diagnostic_params));
        to_json(object, static_cast<const PartialResultParams&>(workspace_diagnostic_params));
        if(workspace_diagnostic_params.identifier.has_value())
            object["identifier"] = *workspace_diagnostic_params.identifier;
        nlohmann::json previousResultIds = nlohmann::json::array();
        for(const PreviousResultId& previousResultId : workspace_diagnostic_params.
        previousResultIds)
            previousResultIds.emplace_back(previousResultId);
        object["previousResultIds"] = previousResultIds;
    }
}

#endif