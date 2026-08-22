// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/WorkspaceEditClientCapabilities.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, WorkspaceEditClientCapabilities&
    workspace_edit_client_capabilities) noexcept -> void
    {
        if(object.contains("documentChanges"))
            workspace_edit_client_capabilities.documentChanges = object.at("documentChanges").get<
            bool>();
        if(object.contains("resourceOperations"))
        {
            workspace_edit_client_capabilities.resourceOperations = std::vector<ResourceOperationKind>{};
            const nlohmann::json& resourceOperations = object.at("resourceOperations");
            for(const nlohmann::json& resourceOperation : resourceOperations)
                workspace_edit_client_capabilities.resourceOperations->emplace_back(
                resourceOperation.get<ResourceOperationKind>());
        }
        if(object.contains("failureHandling"))
            workspace_edit_client_capabilities.failureHandling = object.at("failureHandling").get<
            FailureHandlingKind>();
        if(object.contains("normalizesLineEndings"))
            workspace_edit_client_capabilities.normalizesLineEndings = object.at(
            "normalizesLineEndings").get<bool>();
        if(object.contains("changeAnnotationSupport"))
            workspace_edit_client_capabilities.changeAnnotationSupport = object.at(
            "changeAnnotationSupport").get<ChangeAnnotationsSupportOptions>();
        if(object.contains("metadataSupport"))
            workspace_edit_client_capabilities.metadataSupport = object.at("metadataSupport").get<
            bool>();
        if(object.contains("snippetEditSupport"))
            workspace_edit_client_capabilities.snippetEditSupport = object.at("snippetEditSupport")
            .get<bool>();
    }

    auto to_json(nlohmann::json& object, const WorkspaceEditClientCapabilities&
    workspace_edit_client_capabilities) noexcept -> void
    {
        if(workspace_edit_client_capabilities.documentChanges.has_value())
            object["documentChanges"] = *workspace_edit_client_capabilities.documentChanges;
        if(workspace_edit_client_capabilities.resourceOperations.has_value())
        {
            nlohmann::json resourceOperations = nlohmann::json::array();
            for(const ResourceOperationKind& resourceOperation : *
            workspace_edit_client_capabilities.resourceOperations)
                resourceOperations.emplace_back(resourceOperation);
            object["resourceOperations"] = resourceOperations;
        }
        if(workspace_edit_client_capabilities.failureHandling.has_value())
            object["failureHandling"] = *workspace_edit_client_capabilities.failureHandling;
        if(workspace_edit_client_capabilities.normalizesLineEndings.has_value())
            object["normalizesLineEndings"] = *workspace_edit_client_capabilities.
            normalizesLineEndings;
        if(workspace_edit_client_capabilities.changeAnnotationSupport.has_value())
            object["changeAnnotationSupport"] = *workspace_edit_client_capabilities.
            changeAnnotationSupport;
        if(workspace_edit_client_capabilities.metadataSupport.has_value())
            object["metadataSupport"] = *workspace_edit_client_capabilities.metadataSupport;
        if(workspace_edit_client_capabilities.snippetEditSupport.has_value())
            object["snippetEditSupport"] = *workspace_edit_client_capabilities.snippetEditSupport;
    }
}

#endif