// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/WorkspaceOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, WorkspaceOptions& workspace_options) noexcept ->
    void
    {
        if(object.contains("workspaceFolders"))
            workspace_options.workspaceFolders = object.at("workspaceFolders").get<
            WorkspaceFoldersServerCapabilities>();
        if(object.contains("fileOperations"))
            workspace_options.fileOperations = object.at("fileOperations").get<FileOperationOptions
            >();
        if(object.contains("textDocumentContent"))
        {
            const nlohmann::json& textDocumentContent = object.at("textDocumentContent");
            if(textDocumentContent.contains("id"))
                workspace_options.textDocumentContent = textDocumentContent.get<
                TextDocumentContentRegistrationOptions>();
            else
                workspace_options.textDocumentContent = textDocumentContent.get<
                TextDocumentContentOptions>();
        }
    }

    auto to_json(nlohmann::json& object, const WorkspaceOptions& workspace_options) noexcept ->
    void
    {
        if(workspace_options.workspaceFolders.has_value())
            object["workspaceFolders"] = *workspace_options.workspaceFolders;
        if(workspace_options.fileOperations.has_value())
            object["fileOperations"] = *workspace_options.fileOperations;
        if(workspace_options.textDocumentContent.has_value())
            std::visit([&object](auto&& textDocumentContent)
            {
                object["textDocumentContent"] = textDocumentContent;
            }, *workspace_options.textDocumentContent);
    }
}

#endif