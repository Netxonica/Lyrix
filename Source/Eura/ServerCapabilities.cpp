// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ServerCapabilities.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ServerCapabilities& server_capabilities) noexcept
    -> void
    {
        if(object.contains("positionEncoding"))
            server_capabilities.positionEncoding = object.at("positionEncoding").get<
            PositionEncodingKind>();
        if(object.contains("textDocumentSync"))
        {
            const nlohmann::json& textDocumentSync = object.at("textDocumentSync");
            if(textDocumentSync.is_object())
                server_capabilities.textDocumentSync = textDocumentSync.get<TextDocumentSyncOptions
                >();
            else
                server_capabilities.textDocumentSync = textDocumentSync.get<TextDocumentSyncKind>()
                ;
        }
        if(object.contains("notebookDocumentSync"))
        {
            const nlohmann::json& notebookDocumentSync = object.at("notebookDocumentSync");
            if(notebookDocumentSync.contains("id"))
                server_capabilities.notebookDocumentSync = notebookDocumentSync.get<
                NotebookDocumentSyncRegistrationOptions>();
            else
                server_capabilities.notebookDocumentSync = notebookDocumentSync.get<
                NotebookDocumentSyncOptions>();
        }
        if(object.contains("completionProvider"))
            server_capabilities.completionProvider = object.at("completionProvider").get<
            CompletionOptions>();
        if(object.contains("hoverProvider"))
        {
            const nlohmann::json& hoverProvider = object.at("hoverProvider");
            if(hoverProvider.is_boolean())
                server_capabilities.hoverProvider = hoverProvider.get<bool>();
            else
                server_capabilities.hoverProvider = hoverProvider.get<HoverOptions>();
        }
        if(object.contains("signatureHelpProvider"))
            server_capabilities.signatureHelpProvider = object.at("signatureHelpProvider").get<
            SignatureHelpOptions>();
        if(object.contains("declarationProvider"))
        {
            const nlohmann::json& declarationProvider = object.at("declarationProvider");
            if(declarationProvider.is_boolean())
                server_capabilities.declarationProvider = declarationProvider.get<bool>();
            else if(declarationProvider.contains("documentSelector"))
                server_capabilities.declarationProvider = declarationProvider.get<
                DeclarationRegistrationOptions>();
            else
                server_capabilities.declarationProvider = declarationProvider.get<
                DeclarationOptions>();
        }
        if(object.contains("definitionProvider"))
        {
            const nlohmann::json& definitionProvider = object.at("definitionProvider");
            if(definitionProvider.is_boolean())
                server_capabilities.definitionProvider = definitionProvider.get<bool>();
            else
                server_capabilities.definitionProvider = definitionProvider.get<DefinitionOptions>(
                );
        }
        if(object.contains("typeDefinitionProvider"))
        {
            const nlohmann::json& typeDefinitionProvider = object.at("typeDefinitionProvider");
            if(typeDefinitionProvider.is_boolean())
                server_capabilities.typeDefinitionProvider = typeDefinitionProvider.get<bool>();
            else if(typeDefinitionProvider.contains("documentSelector"))
                server_capabilities.typeDefinitionProvider = typeDefinitionProvider.get<
                TypeDefinitionRegistrationOptions>();
            else
                server_capabilities.typeDefinitionProvider = typeDefinitionProvider.get<
                TypeDefinitionOptions>();
        }
        if(object.contains("implementationProvider"))
        {
            const nlohmann::json& implementationProvider = object.at("implementationProvider");
            if(implementationProvider.is_boolean())
                server_capabilities.implementationProvider = implementationProvider.get<bool>();
            else if(implementationProvider.contains("documentSelector"))
                server_capabilities.implementationProvider = implementationProvider.get<
                ImplementationRegistrationOptions>();
            else
                server_capabilities.implementationProvider = implementationProvider.get<
                ImplementationOptions>();
        }
        if(object.contains("referenceProvider"))
        {
            const nlohmann::json& referenceProvider = object.at("referenceProvider");
            if(referenceProvider.is_boolean())
                server_capabilities.referenceProvider = referenceProvider.get<bool>();
            else
                server_capabilities.referenceProvider = referenceProvider.get<ReferenceOptions>();
        }
        if(object.contains("documentHighlightProvider"))
        {
            const nlohmann::json& documentHighlightProvider = object.at("documentHighlightProvider"
            );
            if(documentHighlightProvider.is_boolean())
                server_capabilities.documentHighlightProvider = documentHighlightProvider.get<bool>
                ();
            else
                server_capabilities.documentHighlightProvider = documentHighlightProvider.get<
                DocumentHighlightOptions>();
        }
        if(object.contains("documentSymbolProvider"))
        {
            const nlohmann::json& documentSymbolProvider = object.at("documentSymbolProvider");
            if(documentSymbolProvider.is_boolean())
                server_capabilities.documentSymbolProvider = documentSymbolProvider.get<bool>();
            else
                server_capabilities.documentSymbolProvider = documentSymbolProvider.get<
                DocumentSymbolOptions>();
        }
        if(object.contains("codeActionProvider"))
        {
            const nlohmann::json& codeActionProvider = object.at("codeActionProvider");
            if(codeActionProvider.is_boolean())
                server_capabilities.codeActionProvider = codeActionProvider.get<bool>();
            else
                server_capabilities.codeActionProvider = codeActionProvider.get<CodeActionOptions>(
                );
        }
        if(object.contains("codeLensProvider"))
            server_capabilities.codeLensProvider = object.at("codeLensProvider").get<
            CodeLensOptions>();
        if(object.contains("documentLinkProvider"))
            server_capabilities.documentLinkProvider = object.at("documentLinkProvider").get<
            DocumentLinkOptions>();
        if(object.contains("colorProvider"))
        {
            const nlohmann::json& colorProvider = object.at("colorProvider");
            if(colorProvider.is_boolean())
                server_capabilities.colorProvider = colorProvider.get<bool>();
            else if(colorProvider.contains("documentSelector"))
                server_capabilities.colorProvider = colorProvider.get<
                DocumentColorRegistrationOptions>();
            else
                server_capabilities.colorProvider = colorProvider.get<DocumentColorOptions>();
        }
        if(object.contains("documentFormattingProvider"))
        {
            const nlohmann::json& documentFormattingProvider = object.at(
            "documentFormattingProvider");
            if(documentFormattingProvider.is_boolean())
                server_capabilities.documentFormattingProvider = documentFormattingProvider.get<
                bool>();
            else
                server_capabilities.documentFormattingProvider = documentFormattingProvider.get<
                DocumentFormattingOptions>();
        }
        if(object.contains("documentRangeFormattingProvider"))
        {
            const nlohmann::json& documentRangeFormattingProvider = object.at(
            "documentRangeFormattingProvider");
            if(documentRangeFormattingProvider.is_boolean())
                server_capabilities.documentRangeFormattingProvider =
                documentRangeFormattingProvider.get<bool>();
            else
                server_capabilities.documentRangeFormattingProvider =
                documentRangeFormattingProvider.get<DocumentRangeFormattingOptions>();
        }
        if(object.contains("documentOnTypeFormattingProvider"))
            server_capabilities.documentOnTypeFormattingProvider = object.at(
            "documentOnTypeFormattingProvider").get<DocumentOnTypeFormattingOptions>();
        if(object.contains("renameProvider"))
        {
            const nlohmann::json& renameProvider = object.at("renameProvider");
            if(renameProvider.is_boolean())
                server_capabilities.renameProvider = renameProvider.get<bool>();
            else
                server_capabilities.renameProvider = renameProvider.get<RenameOptions>();
        }
        if(object.contains("foldingRangeProvider"))
        {
            const nlohmann::json& foldingRangeProvider = object.at("foldingRangeProvider");
            if(foldingRangeProvider.is_boolean())
                server_capabilities.foldingRangeProvider = foldingRangeProvider.get<bool>();
            else if(foldingRangeProvider.contains("documentSelector"))
                server_capabilities.foldingRangeProvider = foldingRangeProvider.get<
                FoldingRangeRegistrationOptions>();
            else
                server_capabilities.foldingRangeProvider = foldingRangeProvider.get<
                FoldingRangeOptions>();
        }
        if(object.contains("executeCommandProvider"))
            server_capabilities.executeCommandProvider = object.at("executeCommandProvider").get<
            ExecuteCommandOptions>();
        if(object.contains("selectionRangeProvider"))
        {
            const nlohmann::json& selectionRangeProvider = object.at("selectionRangeProvider");
            if(selectionRangeProvider.is_boolean())
                server_capabilities.selectionRangeProvider = selectionRangeProvider.get<bool>();
            else if(selectionRangeProvider.contains("documentSelector"))
                server_capabilities.selectionRangeProvider = selectionRangeProvider.get<
                SelectionRangeRegistrationOptions>();
            else
                server_capabilities.selectionRangeProvider = selectionRangeProvider.get<
                SelectionRangeOptions>();
        }
        if(object.contains("linkedEditingRangeProvider"))
        {
            const nlohmann::json& linkedEditingRangeProvider = object.at(
            "linkedEditingRangeProvider");
            if(linkedEditingRangeProvider.is_boolean())
                server_capabilities.linkedEditingRangeProvider = linkedEditingRangeProvider.get<
                bool>();
            else if(linkedEditingRangeProvider.contains("documentSelector"))
                server_capabilities.linkedEditingRangeProvider = linkedEditingRangeProvider.get<
                LinkedEditingRangeRegistrationOptions>();
            else
                server_capabilities.linkedEditingRangeProvider = linkedEditingRangeProvider.get<
                LinkedEditingRangeOptions>();
        }
        if(object.contains("callHierarchyProvider"))
        {
            const nlohmann::json& callHierarchyProvider = object.at("callHierarchyProvider");
            if(callHierarchyProvider.is_boolean())
                server_capabilities.callHierarchyProvider = callHierarchyProvider.get<bool>();
            else if(callHierarchyProvider.contains("documentSelector"))
                server_capabilities.callHierarchyProvider = callHierarchyProvider.get<
                CallHierarchyRegistrationOptions>();
            else
                server_capabilities.callHierarchyProvider = callHierarchyProvider.get<
                CallHierarchyOptions>();
        }
        if(object.contains("semanticTokensProvider"))
        {
            const nlohmann::json& semanticTokensProvider = object.at("semanticTokensProvider");
            if(semanticTokensProvider.contains("documentSelector"))
                server_capabilities.semanticTokensProvider = semanticTokensProvider.get<
                SemanticTokensRegistrationOptions>();
            else
                server_capabilities.semanticTokensProvider = semanticTokensProvider.get<
                SemanticTokensOptions>();
        }
        if(object.contains("monikerProvider"))
        {
            const nlohmann::json& monikerProvider = object.at("monikerProvider");
            if(monikerProvider.is_boolean())
                server_capabilities.monikerProvider = monikerProvider.get<bool>();
            else if(monikerProvider.contains("documentSelector"))
                server_capabilities.monikerProvider = monikerProvider.get<
                MonikerRegistrationOptions>();
            else
                server_capabilities.monikerProvider = monikerProvider.get<MonikerOptions>();
        }
        if(object.contains("typeHierarchyProvider"))
        {
            const nlohmann::json& typeHierarchyProvider = object.at("typeHierarchyProvider");
            if(typeHierarchyProvider.is_boolean())
                server_capabilities.typeHierarchyProvider = typeHierarchyProvider.get<bool>();
            else if(typeHierarchyProvider.contains("documentSelector"))
                server_capabilities.typeHierarchyProvider = typeHierarchyProvider.get<
                TypeHierarchyRegistrationOptions>();
            else
                server_capabilities.typeHierarchyProvider = typeHierarchyProvider.get<
                TypeHierarchyOptions>();
        }
        if(object.contains("inlineValueProvider"))
        {
            const nlohmann::json& inlineValueProvider = object.at("inlineValueProvider");
            if(inlineValueProvider.is_boolean())
                server_capabilities.inlineValueProvider = inlineValueProvider.get<bool>();
            else if(inlineValueProvider.contains("documentSelector"))
                server_capabilities.inlineValueProvider = inlineValueProvider.get<
                InlineValueRegistrationOptions>();
            else
                server_capabilities.inlineValueProvider = inlineValueProvider.get<
                InlineValueOptions>();
        }
        if(object.contains("inlayHintProvider"))
        {
            const nlohmann::json& inlayHintProvider = object.at("inlayHintProvider");
            if(inlayHintProvider.is_boolean())
                server_capabilities.inlayHintProvider = inlayHintProvider.get<bool>();
            else if(inlayHintProvider.contains("documentSelector"))
                server_capabilities.inlayHintProvider = inlayHintProvider.get<
                InlayHintRegistrationOptions>();
            else
                server_capabilities.inlayHintProvider = inlayHintProvider.get<InlayHintOptions>();
        }
        if(object.contains("diagnosticProvider"))
        {
            const nlohmann::json& diagnosticProvider = object.at("diagnosticProvider");
            if(diagnosticProvider.contains("documentSelector"))
                server_capabilities.diagnosticProvider = diagnosticProvider.get<
                DiagnosticRegistrationOptions>();
            else
                server_capabilities.diagnosticProvider = diagnosticProvider.get<DiagnosticOptions>(
                );
        }
        if(object.contains("workspaceSymbolProvider"))
        {
            const nlohmann::json& workspaceSymbolProvider = object.at("workspaceSymbolProvider");
            if(workspaceSymbolProvider.is_boolean())
                server_capabilities.workspaceSymbolProvider = workspaceSymbolProvider.get<bool>();
            else
                server_capabilities.workspaceSymbolProvider = workspaceSymbolProvider.get<
                WorkspaceSymbolOptions>();
        }
        if(object.contains("inlineCompletionProvider"))
        {
            const nlohmann::json& inlineCompletionProvider = object.at("inlineCompletionProvider");
            if(inlineCompletionProvider.is_boolean())
                server_capabilities.inlineCompletionProvider = inlineCompletionProvider.get<bool>()
                ;
            else
                server_capabilities.inlineCompletionProvider = inlineCompletionProvider.get<
                InlineCompletionOptions>();
        }
        if(object.contains("workspace"))
            server_capabilities.workspace = object.at("workspace").get<WorkspaceOptions>();
        if(object.contains("experimental"))
            server_capabilities.experimental = object.at("experimental");
    }

    auto to_json(nlohmann::json& object, const ServerCapabilities& server_capabilities) noexcept ->
    void
    {
        if(server_capabilities.positionEncoding.has_value())
            object["positionEncoding"] = *server_capabilities.positionEncoding;
        if(server_capabilities.textDocumentSync.has_value())
            std::visit([&object](auto&& textDocumentSync)
            {
                object["textDocumentSync"] = textDocumentSync;
            }, *server_capabilities.textDocumentSync);
        if(server_capabilities.notebookDocumentSync.has_value())
            std::visit([&object](auto&& notebookDocumentSync)
            {
                object["notebookDocumentSync"] = notebookDocumentSync;
            }, *server_capabilities.notebookDocumentSync);
        if(server_capabilities.completionProvider.has_value())
            object["completionProvider"] = *server_capabilities.completionProvider;
        if(server_capabilities.hoverProvider.has_value())
            std::visit([&object](auto&& hoverProvider)
            {
                object["hoverProvider"] = hoverProvider;
            }, *server_capabilities.hoverProvider);
        if(server_capabilities.signatureHelpProvider.has_value())
            object["signatureHelpProvider"] = *server_capabilities.signatureHelpProvider;
        if(server_capabilities.declarationProvider.has_value())
            std::visit([&object](auto&& declarationProvider)
            {
                object["declarationProvider"] = declarationProvider;
            }, *server_capabilities.declarationProvider);
        if(server_capabilities.definitionProvider.has_value())
            std::visit([&object](auto&& definitionProvider)
            {
                object["definitionProvider"] = definitionProvider;
            }, *server_capabilities.definitionProvider);
        if(server_capabilities.typeDefinitionProvider.has_value())
            std::visit([&object](auto&& typeDefinitionProvider)
            {
                object["typeDefinitionProvider"] = typeDefinitionProvider;
            }, *server_capabilities.typeDefinitionProvider);
        if(server_capabilities.implementationProvider.has_value())
            std::visit([&object](auto&& implementationProvider)
            {
                object["implementationProvider"] = implementationProvider;
            }, *server_capabilities.implementationProvider);
        if(server_capabilities.referenceProvider.has_value())
            std::visit([&object](auto&& referenceProvider)
            {
                object["referenceProvider"] = referenceProvider;
            }, *server_capabilities.referenceProvider);
        if(server_capabilities.documentHighlightProvider.has_value())
            std::visit([&object](auto&& documentHighlightProvider)
            {
                object["documentHighlightProvider"] = documentHighlightProvider;
            }, *server_capabilities.documentHighlightProvider);
        if(server_capabilities.documentSymbolProvider.has_value())
            std::visit([&object](auto&& documentSymbolProvider)
            {
                object["documentSymbolProvider"] = documentSymbolProvider;
            }, *server_capabilities.documentSymbolProvider);
        if(server_capabilities.codeActionProvider.has_value())
            std::visit([&object](auto&& codeActionProvider)
            {
                object["codeActionProvider"] = codeActionProvider;
            }, *server_capabilities.codeActionProvider);
        if(server_capabilities.codeLensProvider.has_value())
            object["codeLensProvider"] = *server_capabilities.codeLensProvider;
        if(server_capabilities.documentLinkProvider.has_value())
            object["documentLinkProvider"] = *server_capabilities.documentLinkProvider;
        if(server_capabilities.colorProvider.has_value())
            std::visit([&object](auto&& colorProvider)
            {
                object["colorProvider"] = colorProvider;
            }, *server_capabilities.colorProvider);
        if(server_capabilities.documentFormattingProvider.has_value())
            std::visit([&object](auto&& documentFormattingProvider)
            {
                object["documentFormattingProvider"] = documentFormattingProvider;
            }, *server_capabilities.documentFormattingProvider);
        if(server_capabilities.documentRangeFormattingProvider.has_value())
            std::visit([&object](auto&& documentRangeFormattingProvider)
            {
                object["documentRangeFormattingProvider"] = documentRangeFormattingProvider;
            }, *server_capabilities.documentRangeFormattingProvider);
        if(server_capabilities.documentOnTypeFormattingProvider.has_value())
            object["documentOnTypeFormattingProvider"] = *server_capabilities.
            documentOnTypeFormattingProvider;
        if(server_capabilities.renameProvider.has_value())
            std::visit([&object](auto&& renameProvider)
            {
                object["renameProvider"] = renameProvider;
            }, *server_capabilities.renameProvider);
        if(server_capabilities.foldingRangeProvider.has_value())
            std::visit([&object](auto&& foldingRangeProvider)
            {
                object["foldingRangeProvider"] = foldingRangeProvider;
            }, *server_capabilities.foldingRangeProvider);
        if(server_capabilities.executeCommandProvider.has_value())
            object["executeCommandProvider"] = *server_capabilities.executeCommandProvider;
        if(server_capabilities.selectionRangeProvider.has_value())
            std::visit([&object](auto&& selectionRangeProvider)
            {
                object["selectionRangeProvider"] = selectionRangeProvider;
            }, *server_capabilities.selectionRangeProvider);
        if(server_capabilities.linkedEditingRangeProvider.has_value())
            std::visit([&object](auto&& linkedEditingRangeProvider)
            {
                object["linkedEditingRangeProvider"] = linkedEditingRangeProvider;
            }, *server_capabilities.linkedEditingRangeProvider);
        if(server_capabilities.callHierarchyProvider.has_value())
            std::visit([&object](auto&& callHierarchyProvider)
            {
                object["callHierarchyProvider"] = callHierarchyProvider;
            }, *server_capabilities.callHierarchyProvider);
        if(server_capabilities.semanticTokensProvider.has_value())
            std::visit([&object](auto&& semanticTokensProvider)
            {
                object["semanticTokensProvider"] = semanticTokensProvider;
            }, *server_capabilities.semanticTokensProvider);
        if(server_capabilities.monikerProvider.has_value())
            std::visit([&object](auto&& monikerProvider)
            {
                object["monikerProvider"] = monikerProvider;
            }, *server_capabilities.monikerProvider);
        if(server_capabilities.typeHierarchyProvider.has_value())
            std::visit([&object](auto&& typeHierarchyProvider)
            {
                object["typeHierarchyProvider"] = typeHierarchyProvider;
            }, *server_capabilities.typeHierarchyProvider);
        if(server_capabilities.inlineValueProvider.has_value())
            std::visit([&object](auto&& inlineValueProvider)
            {
                object["inlineValueProvider"] = inlineValueProvider;
            }, *server_capabilities.inlineValueProvider);
        if(server_capabilities.inlayHintProvider.has_value())
            std::visit([&object](auto&& inlayHintProvider)
            {
                object["inlayHintProvider"] = inlayHintProvider;
            }, *server_capabilities.inlayHintProvider);
        if(server_capabilities.diagnosticProvider.has_value())
            std::visit([&object](auto&& diagnosticProvider)
            {
                object["diagnosticProvider"] = diagnosticProvider;
            }, *server_capabilities.diagnosticProvider);
        if(server_capabilities.workspaceSymbolProvider.has_value())
            std::visit([&object](auto&& workspaceSymbolProvider)
            {
                object["workspaceSymbolProvider"] = workspaceSymbolProvider;
            }, *server_capabilities.workspaceSymbolProvider);
        if(server_capabilities.inlineCompletionProvider.has_value())
            std::visit([&object](auto&& inlineCompletionProvider)
            {
                object["inlineCompletionProvider"] = inlineCompletionProvider;
            }, *server_capabilities.inlineCompletionProvider);
        if(server_capabilities.workspace.has_value())
            object["workspace"] = *server_capabilities.workspace;
        if(server_capabilities.experimental.has_value())
            object["experimental"] = *server_capabilities.experimental;
    }
}

#endif