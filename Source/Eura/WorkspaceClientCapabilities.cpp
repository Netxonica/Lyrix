// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/WorkspaceClientCapabilities.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, WorkspaceClientCapabilities&
    workspace_client_capabilities) noexcept -> void
    {
        if(object.contains("applyEdit"))
            workspace_client_capabilities.applyEdit = object.at("applyEdit").get<bool>();
        if(object.contains("workspaceEdit"))
            workspace_client_capabilities.workspaceEdit = object.at("workspaceEdit").get<
            WorkspaceEditClientCapabilities>();
        if(object.contains("didChangeConfiguration"))
            workspace_client_capabilities.didChangeConfiguration = object.at(
            "didChangeConfiguration").get<DidChangeConfigurationClientCapabilities>();
        if(object.contains("didChangeWatchedFiles"))
            workspace_client_capabilities.didChangeWatchedFiles = object.at("didChangeWatchedFiles"
            ).get<DidChangeWatchedFilesClientCapabilities>();
        if(object.contains("symbol"))
            workspace_client_capabilities.symbol = object.at("symbol").get<
            WorkspaceSymbolClientCapabilities>();
        if(object.contains("executeCommand"))
            workspace_client_capabilities.executeCommand = object.at("executeCommand").get<
            ExecuteCommandClientCapabilities>();
        if(object.contains("workspaceFolders"))
            workspace_client_capabilities.workspaceFolders = object.at("workspaceFolders").get<bool
            >();
        if(object.contains("configuration"))
            workspace_client_capabilities.configuration = object.at("configuration").get<bool>();
        if(object.contains("semanticTokens"))
            workspace_client_capabilities.semanticTokens = object.at("semanticTokens").get<
            SemanticTokensWorkspaceClientCapabilities>();
        if(object.contains("codeLens"))
            workspace_client_capabilities.codeLens = object.at("codeLens").get<
            CodeLensWorkspaceClientCapabilities>();
        if(object.contains("fileOperations"))
            workspace_client_capabilities.fileOperations = object.at("fileOperations").get<
            FileOperationClientCapabilities>();
        if(object.contains("inlineValue"))
            workspace_client_capabilities.inlineValue = object.at("inlineValue").get<
            InlineValueWorkspaceClientCapabilities>();
        if(object.contains("inlayHint"))
            workspace_client_capabilities.inlayHint = object.at("inlayHint").get<
            InlayHintWorkspaceClientCapabilities>();
        if(object.contains("diagnostics"))
            workspace_client_capabilities.diagnostics = object.at("diagnostics").get<
            DiagnosticWorkspaceClientCapabilities>();
        if(object.contains("foldingRange"))
            workspace_client_capabilities.foldingRange = object.at("foldingRange").get<
            FoldingRangeWorkspaceClientCapabilities>();
        if(object.contains("textDocumentContent"))
            workspace_client_capabilities.textDocumentContent = object.at("textDocumentContent").
            get<TextDocumentContentClientCapabilities>();
    }

    auto to_json(nlohmann::json& object, const WorkspaceClientCapabilities&
    workspace_client_capabilities) noexcept -> void
    {
        if(workspace_client_capabilities.applyEdit.has_value())
            object["applyEdit"] = *workspace_client_capabilities.applyEdit;
        if(workspace_client_capabilities.workspaceEdit.has_value())
            object["workspaceEdit"] = *workspace_client_capabilities.workspaceEdit;
        if(workspace_client_capabilities.didChangeConfiguration.has_value())
            object["didChangeConfiguration"] = *workspace_client_capabilities.
            didChangeConfiguration;
        if(workspace_client_capabilities.didChangeWatchedFiles.has_value())
            object["didChangeWatchedFiles"] = *workspace_client_capabilities.didChangeWatchedFiles;
        if(workspace_client_capabilities.symbol.has_value())
            object["symbol"] = *workspace_client_capabilities.symbol;
        if(workspace_client_capabilities.executeCommand.has_value())
            object["executeCommand"] = *workspace_client_capabilities.executeCommand;
        if(workspace_client_capabilities.workspaceFolders.has_value())
            object["workspaceFolders"] = *workspace_client_capabilities.workspaceFolders;
        if(workspace_client_capabilities.configuration.has_value())
            object["configuration"] = *workspace_client_capabilities.configuration;
        if(workspace_client_capabilities.semanticTokens.has_value())
            object["semanticTokens"] = *workspace_client_capabilities.semanticTokens;
        if(workspace_client_capabilities.codeLens.has_value())
            object["codeLens"] = *workspace_client_capabilities.codeLens;
        if(workspace_client_capabilities.fileOperations.has_value())
            object["fileOperations"] = *workspace_client_capabilities.fileOperations;
        if(workspace_client_capabilities.inlineValue.has_value())
            object["inlineValue"] = *workspace_client_capabilities.inlineValue;
        if(workspace_client_capabilities.inlayHint.has_value())
            object["inlayHint"] = *workspace_client_capabilities.inlayHint;
        if(workspace_client_capabilities.diagnostics.has_value())
            object["diagnostics"] = *workspace_client_capabilities.diagnostics;
        if(workspace_client_capabilities.foldingRange.has_value())
            object["foldingRange"] = *workspace_client_capabilities.foldingRange;
        if(workspace_client_capabilities.textDocumentContent.has_value())
            object["textDocumentContent"] = *workspace_client_capabilities.textDocumentContent;
    }
}

#endif