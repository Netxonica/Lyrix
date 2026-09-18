// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Message.hpp"
#include "Eura/InitializeResult.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"capabilities\":{\"positionEncoding\":\"utf-8\",\"textDocumentSync\":{\"openClose\":true,\"change\":2},\"notebookDocumentSync\":{\"notebookSelector\":[{\"notebook\":{\"notebookType\":\"lyrix\",\"scheme\":\"meow.lyrix\",\"pattern\":{\"baseUri\":{\"uri\":\"meow.extension\",\"name\":\"meow nya\"},\"pattern\":\"*.extension\"}},\"cells\":[{\"language\":\"lyrix\"}]}],\"save\":true},\"completionProvider\":{\"workDoneProgress\":true,\"triggerCharacters\":[\"meow\"],\"allCommitCharacters\":[\"nya\"],\"resolveProvider\":true,\"completionItem\":{\"labelDetailsSupport\":true}},\"hoverProvider\":true,\"signatureHelpProvider\":{\"workDoneProgress\":true,\"triggerCharacters\":[\"meow\"],\"retriggerCharacters\":[\"nya\"]},\"declarationProvider\":true,\"definitionProvider\":true,\"typeDefinitionProvider\":true,\"implementationProvider\":true,\"referenceProvider\":true,\"documentHighlightProvider\":true,\"documentSymbolProvider\":true,\"codeActionProvider\":true,\"codeLensProvider\":{\"workDoneProgress\":true,\"resolveProvider\":true},\"documentLinkProvider\":{\"workDoneProgress\":true,\"resolveProvider\":true},\"colorProvider\":true,\"documentFormattingProvider\":true,\"documentRangeFormattingProvider\":true,\"documentOnTypeFormattingProvider\":{\"firstTriggerCharacter\":\"meow\",\"moreTriggerCharacter\":[\"nya\"]},\"renameProvider\":true,\"foldingRangeProvider\":true,\"executeCommandProvider\":{\"workDoneProgress\":true,\"commands\":[]},\"selectionRangeProvider\":true,\"linkedEditingRangeProvider\":true,\"callHierarchyProvider\":true,\"semanticTokensProvider\":{\"workDoneProgress\":true,\"legend\":{\"tokenTypes\":[\"meow\"],\"tokenModifiers\":[\"nya\"]},\"range\":{},\"full\":{\"delta\":true}},\"monikerProvider\":true,\"typeHierarchyProvider\":true,\"inlineValueProvider\":true,\"inlayHintProvider\":true,\"diagnosticProvider\":{\"workDoneProgress\":true,\"identifier\":\"meow\",\"interFileDependencies\":true,\"workspaceDiagnostics\":true},\"workspaceSymbolProvider\":true,\"inlineCompletionProvider\":true,\"experimental\":{\"jsonrpc\":\"2.0\"}},\"serverInfo\":{\"name\":\"lyrix\",\"version\":\"nya\"}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::InitializeResult request;
    Eura::from_json(root, request);
    if(not request.capabilities.positionEncoding.has_value() or *request.capabilities.
    positionEncoding not_eq Eura::UTF8 or not request.capabilities.textDocumentSync.has_value() or
    not std::holds_alternative<Eura::TextDocumentSyncOptions>(*request.capabilities.
    textDocumentSync))
        return false;
    const Eura::TextDocumentSyncOptions& textDocumentSync = std::get<Eura::TextDocumentSyncOptions>
    (*request.capabilities.textDocumentSync);
    if(not textDocumentSync.openClose.has_value() or not *textDocumentSync.openClose or not
    textDocumentSync.change.has_value() or *textDocumentSync.change not_eq Eura::
    TextDocumentSyncKind::Incremental or not request.capabilities.notebookDocumentSync.has_value()
    or not std::holds_alternative<Eura::NotebookDocumentSyncOptions>(*request.capabilities.
    notebookDocumentSync))
        return false;
    const Eura::NotebookDocumentSyncOptions& notebookDocumentSync = std::get<Eura::
    NotebookDocumentSyncOptions>(*request.capabilities.notebookDocumentSync);
    if(notebookDocumentSync.notebookSelector.size() not_eq 1uz)
        return false;
    const Eura::NotebookDocumentFilterWithNotebook& notebook_selector = notebookDocumentSync.
    notebookSelector[0uz];
    if(not notebook_selector.notebook.has_value() or not std::holds_alternative<Eura::
    NotebookDocumentFilter>(*notebook_selector.notebook))
        return false;
    const Eura::NotebookDocumentFilter& notebook_document_filter = std::get<Eura::
    NotebookDocumentFilter>(*notebook_selector.notebook);
    if(not notebook_document_filter.notebookType.has_value() or *notebook_document_filter.
    notebookType not_eq "lyrix" or not notebook_document_filter.scheme.has_value() or *
    notebook_document_filter.scheme not_eq "meow.lyrix" or not notebook_document_filter.pattern.
    has_value() or not std::holds_alternative<Eura::RelativePattern>(*notebook_document_filter.
    pattern))
        return false;
    const Eura::RelativePattern& relative_pattern = std::get<Eura::RelativePattern>(*
    notebook_document_filter.pattern);
    if(not std::holds_alternative<Eura::WorkspaceFolder>(relative_pattern.baseUri))
        return false;
    const Eura::WorkspaceFolder& workspace_folder = std::get<Eura::WorkspaceFolder>(
    relative_pattern.baseUri);
    if(workspace_folder.uri not_eq "meow.extension" or workspace_folder.name not_eq "meow nya" or
    relative_pattern.pattern not_eq "*.extension" or not notebook_selector.cells.has_value() or
    notebook_selector.cells->size() not_eq 1uz or (*notebook_selector.cells)[0uz].language not_eq
    "lyrix" or not notebookDocumentSync.save.has_value() or not *notebookDocumentSync.save or not
    request.capabilities.completionProvider.has_value() or not request.capabilities.
    completionProvider->workDoneProgress.has_value() or not *request.capabilities.
    completionProvider->workDoneProgress or not request.capabilities.completionProvider->
    triggerCharacters.has_value() or request.capabilities.completionProvider->triggerCharacters->
    size() not_eq 1uz or (*request.capabilities.completionProvider->triggerCharacters)[0uz] not_eq
    "meow" or not request.capabilities.completionProvider->allCommitCharacters.has_value() or
    request.capabilities.completionProvider->allCommitCharacters->size() not_eq 1uz or (*request.
    capabilities.completionProvider->allCommitCharacters)[0uz] not_eq "nya" or not request.
    capabilities.completionProvider->resolveProvider.has_value() or not *request.capabilities.
    completionProvider->resolveProvider or not request.capabilities.completionProvider->
    completionItem.has_value() or not request.capabilities.completionProvider->completionItem->
    labelDetailsSupport.has_value() or not *request.capabilities.completionProvider->completionItem
    ->labelDetailsSupport or not request.capabilities.hoverProvider.has_value() or not std::
    holds_alternative<bool>(*request.capabilities.hoverProvider) or not std::get<bool>(*request.
    capabilities.hoverProvider) or not request.capabilities.signatureHelpProvider.has_value() or
    not request.capabilities.signatureHelpProvider->workDoneProgress.has_value() or not *request.
    capabilities.signatureHelpProvider->workDoneProgress or not request.capabilities.
    signatureHelpProvider->triggerCharacters.has_value() or request.capabilities.
    signatureHelpProvider->triggerCharacters->size() not_eq 1uz or (*request.capabilities.
    signatureHelpProvider->triggerCharacters)[0uz] not_eq "meow" or not request.capabilities.
    signatureHelpProvider->retriggerCharacters.has_value() or request.capabilities.
    signatureHelpProvider->retriggerCharacters->size() not_eq 1uz or (*request.capabilities.
    signatureHelpProvider->retriggerCharacters)[0uz] not_eq "nya" or not request.capabilities.
    declarationProvider.has_value() or not std::holds_alternative<bool>(*request.capabilities.
    declarationProvider) or not std::get<bool>(*request.capabilities.declarationProvider) or not
    request.capabilities.definitionProvider.has_value() or not std::holds_alternative<bool>(*
    request.capabilities.definitionProvider) or not std::get<bool>(*request.capabilities.
    definitionProvider) or not request.capabilities.typeDefinitionProvider.has_value() or not std::
    holds_alternative<bool>(*request.capabilities.typeDefinitionProvider) or not std::get<bool>(*
    request.capabilities.typeDefinitionProvider) or not request.capabilities.implementationProvider
    .has_value() or not std::holds_alternative<bool>(*request.capabilities.implementationProvider)
    or not std::get<bool>(*request.capabilities.implementationProvider) or not request.capabilities
    .referenceProvider.has_value() or not std::holds_alternative<bool>(*request.capabilities.
    referenceProvider) or not std::get<bool>(*request.capabilities.referenceProvider) or not
    request.capabilities.documentHighlightProvider.has_value() or not std::holds_alternative<bool>(
    *request.capabilities.documentHighlightProvider) or not std::get<bool>(*request.capabilities.
    documentHighlightProvider) or not request.capabilities.documentSymbolProvider.has_value() or
    not std::holds_alternative<bool>(*request.capabilities.documentSymbolProvider) or not std::get<
    bool>(*request.capabilities.documentSymbolProvider) or not request.capabilities.
    codeActionProvider.has_value() or not std::holds_alternative<bool>(*request.capabilities.
    codeActionProvider) or not std::get<bool>(*request.capabilities.codeActionProvider) or not
    request.capabilities.codeLensProvider.has_value() or not request.capabilities.codeLensProvider
    ->workDoneProgress.has_value() or not *request.capabilities.codeLensProvider->workDoneProgress
    or not request.capabilities.codeLensProvider->resolveProvider.has_value() or not *request.
    capabilities.codeLensProvider->resolveProvider or not request.capabilities.documentLinkProvider
    .has_value() or not request.capabilities.documentLinkProvider->workDoneProgress.has_value() or
    not *request.capabilities.documentLinkProvider->workDoneProgress or not request.capabilities.
    documentLinkProvider->resolveProvider.has_value() or not *request.capabilities.
    documentLinkProvider->resolveProvider or not request.capabilities.colorProvider.has_value() or
    not std::holds_alternative<bool>(*request.capabilities.colorProvider) or not std::get<bool>(*
    request.capabilities.colorProvider) or not request.capabilities.documentFormattingProvider.
    has_value() or not std::holds_alternative<bool>(*request.capabilities.
    documentFormattingProvider) or not std::get<bool>(*request.capabilities.
    documentFormattingProvider) or not request.capabilities.documentRangeFormattingProvider.
    has_value() or not std::holds_alternative<bool>(*request.capabilities.
    documentRangeFormattingProvider) or not std::get<bool>(*request.capabilities.
    documentRangeFormattingProvider) or not request.capabilities.documentOnTypeFormattingProvider.
    has_value() or request.capabilities.documentOnTypeFormattingProvider->firstTriggerCharacter
    not_eq "meow" or not request.capabilities.documentOnTypeFormattingProvider->
    moreTriggerCharacter.has_value() or request.capabilities.documentOnTypeFormattingProvider->
    moreTriggerCharacter->size() not_eq 1uz or (*request.capabilities.
    documentOnTypeFormattingProvider->moreTriggerCharacter)[0uz] not_eq "nya" or not request.
    capabilities.renameProvider.has_value() or not std::holds_alternative<bool>(*request.
    capabilities.renameProvider) or not std::get<bool>(*request.capabilities.renameProvider) or not
    request.capabilities.foldingRangeProvider.has_value() or not std::holds_alternative<bool>(*
    request.capabilities.foldingRangeProvider) or not std::get<bool>(*request.capabilities.
    foldingRangeProvider) or not request.capabilities.executeCommandProvider.has_value() or not
    request.capabilities.executeCommandProvider->workDoneProgress.has_value() or not *request.
    capabilities.executeCommandProvider->workDoneProgress or not request.capabilities.
    executeCommandProvider->commands.empty() or not request.capabilities.selectionRangeProvider.
    has_value() or not std::holds_alternative<bool>(*request.capabilities.selectionRangeProvider)
    or not std::get<bool>(*request.capabilities.selectionRangeProvider) or not request.capabilities
    .linkedEditingRangeProvider.has_value() or not std::holds_alternative<bool>(*request.
    capabilities.linkedEditingRangeProvider) or not std::get<bool>(*request.capabilities.
    linkedEditingRangeProvider) or not request.capabilities.callHierarchyProvider.has_value() or
    not std::holds_alternative<bool>(*request.capabilities.callHierarchyProvider) or not std::get<
    bool>(*request.capabilities.callHierarchyProvider) or not request.capabilities.
    semanticTokensProvider.has_value() or not std::holds_alternative<Eura::SemanticTokensOptions>(*
    request.capabilities.semanticTokensProvider))
        return false;
    const Eura::SemanticTokensOptions& semanticTokensProvider = std::get<Eura::
    SemanticTokensOptions>(*request.capabilities.semanticTokensProvider);
    if(not semanticTokensProvider.workDoneProgress.has_value() or not *semanticTokensProvider.
    workDoneProgress or semanticTokensProvider.legend.tokenTypes.size() not_eq 1uz or
    semanticTokensProvider.legend.tokenTypes[0uz] not_eq "meow" or semanticTokensProvider.legend.
    tokenModifiers.size() not_eq 1uz or semanticTokensProvider.legend.tokenModifiers[0uz] not_eq
    "nya" or not semanticTokensProvider.range.has_value() or not std::holds_alternative<Eura::Empty
    >(*semanticTokensProvider.range) or not semanticTokensProvider.full.has_value() or not std::
    holds_alternative<Eura::SemanticTokensFullDelta>(*semanticTokensProvider.full))
        return false;
    const Eura::SemanticTokensFullDelta& full = std::get<Eura::SemanticTokensFullDelta>(*
    semanticTokensProvider.full);
    if(not full.delta.has_value() or not *full.delta or not request.capabilities.monikerProvider.
    has_value() or not std::holds_alternative<bool>(*request.capabilities.monikerProvider) or not
    std::get<bool>(*request.capabilities.monikerProvider) or not request.capabilities.
    typeHierarchyProvider.has_value() or not std::holds_alternative<bool>(*request.capabilities.
    typeHierarchyProvider) or not std::get<bool>(*request.capabilities.typeHierarchyProvider) or
    not request.capabilities.inlineValueProvider.has_value() or not std::holds_alternative<bool>(*
    request.capabilities.inlineValueProvider) or not std::get<bool>(*request.capabilities.
    inlineValueProvider) or not request.capabilities.inlayHintProvider.has_value() or not std::
    holds_alternative<bool>(*request.capabilities.inlayHintProvider) or not std::get<bool>(*request
    .capabilities.inlayHintProvider) or not request.capabilities.diagnosticProvider.has_value() or
    not std::holds_alternative<Eura::DiagnosticOptions>(*request.capabilities.diagnosticProvider))
        return false;
    const Eura::DiagnosticOptions& diagnosticProvider = std::get<Eura::DiagnosticOptions>(*request.
    capabilities.diagnosticProvider);
    if(not diagnosticProvider.workDoneProgress.has_value() or not *diagnosticProvider.
    workDoneProgress or not diagnosticProvider.identifier.has_value() or *diagnosticProvider.
    identifier not_eq "meow" or not diagnosticProvider.interFileDependencies or not
    diagnosticProvider.workspaceDiagnostics or not request.capabilities.workspaceSymbolProvider.
    has_value() or not std::holds_alternative<bool>(*request.capabilities.workspaceSymbolProvider)
    or not std::get<bool>(*request.capabilities.workspaceSymbolProvider) or not request
    .capabilities.inlineCompletionProvider.has_value() or not std::holds_alternative<bool>(*request
    .capabilities.inlineCompletionProvider) or not std::get<bool>(*request.capabilities.
    inlineCompletionProvider) or request.capabilities.workspace.has_value() or not request.
    capabilities.experimental.has_value())
        return false;
    Eura::Message message;
    from_json(*request.capabilities.experimental, message);
    if(message.jsonrpc not_eq "2.0" or not request.serverInfo.has_value() or request.serverInfo->
    name not_eq "lyrix" or not request.serverInfo->version.has_value() or *request.serverInfo->
    version not_eq "nya")
        return false;
    nlohmann::json response;
    Eura::to_json(response, request);
    return response.dump() == root.dump();
}

int main()
{
    return not lyrix_test();
}

#endif