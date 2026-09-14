// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Message.hpp"
#include "Eura/ServerCapabilities.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"positionEncoding\":\"utf-8\",\"textDocumentSync\":{\"openClose\":true,\"change\":2},\"notebookDocumentSync\":{\"notebookSelector\":[{\"notebook\":{\"notebookType\":\"lyrix\",\"scheme\":\"meow.lyrix\",\"pattern\":{\"baseUri\":{\"uri\":\"meow.extension\",\"name\":\"meow nya\"},\"pattern\":\"*.extension\"}},\"cells\":[{\"language\":\"lyrix\"}]}],\"save\":true,\"id\":\"meow\"},\"completionProvider\":{\"workDoneProgress\":true,\"triggerCharacters\":[\"meow\"],\"allCommitCharacters\":[\"nya\"],\"resolveProvider\":true,\"completionItem\":{\"labelDetailsSupport\":true}},\"hoverProvider\":{\"workDoneProgress\":true},\"signatureHelpProvider\":{\"workDoneProgress\":true,\"triggerCharacters\":[\"meow\"],\"retriggerCharacters\":[\"nya\"]},\"declarationProvider\":{\"workDoneProgress\":true,\"documentSelector\":[{\"language\":\"lyrix\",\"scheme\":\"meow.lyrix\",\"pattern\":{\"baseUri\":{\"uri\":\"meow.extension\",\"name\":\"meow nya\"},\"pattern\":\"*.extension\"}},{\"notebook\":{\"notebookType\":\"lyrix\",\"scheme\":\"meow.lyrix\",\"pattern\":{\"baseUri\":{\"uri\":\"meow.extension\",\"name\":\"meow nya\"},\"pattern\":\"*.extension\"}},\"language\":\"lyrix\"}],\"id\":\"meow\"},\"definitionProvider\":{\"workDoneProgress\":true},\"typeDefinitionProvider\":true,\"implementationProvider\":true,\"referenceProvider\":true,\"documentHighlightProvider\":true,\"documentSymbolProvider\":true,\"codeActionProvider\":true,\"codeLensProvider\":{\"workDoneProgress\":true,\"resolveProvider\":true},\"documentLinkProvider\":{\"workDoneProgress\":true,\"resolveProvider\":true},\"colorProvider\":true,\"documentFormattingProvider\":true,\"documentRangeFormattingProvider\":true,\"documentOnTypeFormattingProvider\":{\"firstTriggerCharacter\":\"meow\",\"moreTriggerCharacter\":[\"nya\"]},\"renameProvider\":true,\"foldingRangeProvider\":true,\"executeCommandProvider\":{\"workDoneProgress\":true,\"commands\":[]},\"selectionRangeProvider\":true,\"linkedEditingRangeProvider\":true,\"callHierarchyProvider\":true,\"semanticTokensProvider\":{\"workDoneProgress\":true,\"legend\":{\"tokenTypes\":[\"meow\"],\"tokenModifiers\":[\"nya\"]},\"range\":{},\"full\":{\"delta\":true}},\"monikerProvider\":true,\"typeHierarchyProvider\":true,\"inlineValueProvider\":true,\"inlayHintProvider\":true,\"diagnosticProvider\":{\"workDoneProgress\":true,\"identifier\":\"meow\",\"interFileDependencies\":true,\"workspaceDiagnostics\":true},\"workspaceSymbolProvider\":true,\"inlineCompletionProvider\":true,\"experimental\":{\"jsonrpc\":\"2.0\"}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::ServerCapabilities request;
    Eura::from_json(root, request);
    if(not request.positionEncoding.has_value() or *request.positionEncoding not_eq Eura::UTF8 or
    not request.textDocumentSync.has_value() or not std::holds_alternative<Eura::
    TextDocumentSyncOptions>(*request.textDocumentSync))
        return false;
    const Eura::TextDocumentSyncOptions& textDocumentSync = std::get<Eura::TextDocumentSyncOptions>
    (*request.textDocumentSync);
    if(not textDocumentSync.openClose.has_value() or not *textDocumentSync.openClose or not
    textDocumentSync.change.has_value() or *textDocumentSync.change not_eq Eura::
    TextDocumentSyncKind::Incremental or not request.notebookDocumentSync.has_value() or not std::
    holds_alternative<Eura::NotebookDocumentSyncRegistrationOptions>(*request.notebookDocumentSync)
    )
        return false;
    const Eura::NotebookDocumentSyncRegistrationOptions& notebookDocumentSync = std::get<Eura::
    NotebookDocumentSyncRegistrationOptions>(*request.notebookDocumentSync);
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
    notebookDocumentSync.id.has_value() or *notebookDocumentSync.id not_eq "meow" or not request.
    completionProvider.has_value() or not request.completionProvider->workDoneProgress.has_value()
    or not *request.completionProvider->workDoneProgress or not request.completionProvider->
    triggerCharacters.has_value() or request.completionProvider->triggerCharacters->size() not_eq
    1uz or (*request.completionProvider->triggerCharacters)[0uz] not_eq "meow" or not request.
    completionProvider->allCommitCharacters.has_value() or request.completionProvider->
    allCommitCharacters->size() not_eq 1uz or (*request.completionProvider->allCommitCharacters)[
    0uz] not_eq "nya" or not request.completionProvider->resolveProvider.has_value() or not *
    request.completionProvider->resolveProvider or not request.completionProvider->completionItem.
    has_value() or not request.completionProvider->completionItem->labelDetailsSupport.has_value()
    or not *request.completionProvider->completionItem->labelDetailsSupport or not request.
    hoverProvider.has_value() or not std::holds_alternative<Eura::HoverOptions>(*request.
    hoverProvider))
        return false;
    const Eura::HoverOptions& hoverProvider = std::get<Eura::HoverOptions>(*request.hoverProvider);
    if(not hoverProvider.workDoneProgress.has_value() or not *hoverProvider.workDoneProgress or not
    request.signatureHelpProvider.has_value() or not request.signatureHelpProvider->
    workDoneProgress.has_value() or not *request.signatureHelpProvider->workDoneProgress or not
    request.signatureHelpProvider->triggerCharacters.has_value() or request.signatureHelpProvider->
    triggerCharacters->size() not_eq 1uz or (*request.signatureHelpProvider->triggerCharacters)[0uz
    ] not_eq "meow" or not request.signatureHelpProvider->retriggerCharacters.has_value() or
    request.signatureHelpProvider->retriggerCharacters->size() not_eq 1uz or (*request.
    signatureHelpProvider->retriggerCharacters)[0uz] not_eq "nya" or not request.
    declarationProvider.has_value() or not std::holds_alternative<Eura::
    DeclarationRegistrationOptions>(*request.declarationProvider))
        return false;
    const Eura::DeclarationRegistrationOptions& declarationProvider = std::get<Eura::
    DeclarationRegistrationOptions>(*request.declarationProvider);
    if(not declarationProvider.workDoneProgress.has_value() or not *declarationProvider.
    workDoneProgress or not std::holds_alternative<Eura::DocumentSelector>(declarationProvider.
    documentSelector))
        return false;
    const Eura::DocumentSelector& documentSelector = std::get<Eura::DocumentSelector>(
    declarationProvider.documentSelector);
    if(documentSelector.size() not_eq 2uz or not std::holds_alternative<Eura::TextDocumentFilter>(
    documentSelector[0uz]) or not std::holds_alternative<Eura::NotebookCellTextDocumentFilter>(
    documentSelector[1uz]))
        return false;
    const Eura::TextDocumentFilter& text_document_filter = std::get<Eura::TextDocumentFilter>(
    documentSelector[0uz]);
    if(not text_document_filter.language.has_value() or *text_document_filter.language not_eq
    "lyrix" or not text_document_filter.scheme.has_value() or *text_document_filter.scheme not_eq
    "meow.lyrix" or not text_document_filter.pattern.has_value() or not std::holds_alternative<Eura
    ::RelativePattern>(*text_document_filter.pattern))
        return false;
    {
    const Eura::RelativePattern& relative_pattern = std::get<Eura::RelativePattern>(*
    text_document_filter.pattern);
    if(not std::holds_alternative<Eura::WorkspaceFolder>(relative_pattern.baseUri))
        return false;
    const Eura::WorkspaceFolder& workspace_folder = std::get<Eura::WorkspaceFolder>(
    relative_pattern.baseUri);
    if(workspace_folder.uri not_eq "meow.extension" or workspace_folder.name not_eq "meow nya" or
    relative_pattern.pattern not_eq "*.extension")
        return false;
    const Eura::NotebookCellTextDocumentFilter& notebook_cell_text_document_filter = std::get<Eura
    ::NotebookCellTextDocumentFilter>(documentSelector[1uz]);
    if(not std::holds_alternative<Eura::NotebookDocumentFilter>(notebook_cell_text_document_filter.
    notebook))
        return false;
    const Eura::NotebookDocumentFilter& notebook = std::get<Eura::NotebookDocumentFilter>(
    notebook_cell_text_document_filter.notebook);
    if(not notebook.notebookType.has_value() or *notebook.notebookType not_eq "lyrix" or not
    notebook.scheme.has_value() or *notebook.scheme not_eq "meow.lyrix" or not notebook.pattern.
    has_value() or not std::holds_alternative<Eura::RelativePattern>(*notebook.pattern))
        return false;
    const Eura::RelativePattern& rrelative_pattern = std::get<Eura::RelativePattern>(*notebook.
    pattern);
    if(not std::holds_alternative<Eura::WorkspaceFolder>(rrelative_pattern.baseUri))
        return false;
    const Eura::WorkspaceFolder& wworkspace_folder = std::get<Eura::WorkspaceFolder>(
    rrelative_pattern.baseUri);
    if(wworkspace_folder.uri not_eq "meow.extension" or wworkspace_folder.name not_eq "meow nya" or
    rrelative_pattern.pattern not_eq "*.extension" or not notebook_cell_text_document_filter.
    language.has_value() or *notebook_cell_text_document_filter.language not_eq "lyrix" or not
    declarationProvider.id.has_value() or *declarationProvider.id not_eq "meow" or not request.
    definitionProvider.has_value() or not std::holds_alternative<Eura::DefinitionOptions>(*request.
    definitionProvider))
        return false;
    }
    const Eura::DefinitionOptions& definitionProvider = std::get<Eura::DefinitionOptions>(*request.
    definitionProvider);
    if(not definitionProvider.workDoneProgress.has_value() or not *definitionProvider.
    workDoneProgress or not request.typeDefinitionProvider.has_value() or not std::
    holds_alternative<bool>(*request.typeDefinitionProvider) or not std::get<bool>(*request.
    typeDefinitionProvider) or not request.implementationProvider.has_value() or not std::
    holds_alternative<bool>(*request.implementationProvider) or not std::get<bool>(*request.
    implementationProvider) or not request.referenceProvider.has_value() or not std::
    holds_alternative<bool>(*request.referenceProvider) or not std::get<bool>(*request.
    referenceProvider) or not request.documentHighlightProvider.has_value() or not std::
    holds_alternative<bool>(*request.documentHighlightProvider) or not std::get<bool>(*request.
    documentHighlightProvider) or not request.documentSymbolProvider.has_value() or not std::
    holds_alternative<bool>(*request.documentSymbolProvider) or not std::get<bool>(*request.
    documentSymbolProvider) or not request.codeActionProvider.has_value() or not std::
    holds_alternative<bool>(*request.codeActionProvider) or not std::get<bool>(*request.
    codeActionProvider) or not request.codeLensProvider.has_value() or not request.codeLensProvider
    ->workDoneProgress.has_value() or not *request.codeLensProvider->workDoneProgress or not
    request.codeLensProvider->resolveProvider.has_value() or not *request.codeLensProvider->
    resolveProvider or not request.documentLinkProvider.has_value() or not request.
    documentLinkProvider->workDoneProgress.has_value() or not *request.documentLinkProvider->
    workDoneProgress or not request.documentLinkProvider->resolveProvider.has_value() or not *
    request.documentLinkProvider->resolveProvider or not request.colorProvider.has_value() or not
    std::holds_alternative<bool>(*request.colorProvider) or not std::get<bool>(*request.
    colorProvider) or not request.documentFormattingProvider.has_value() or not std::
    holds_alternative<bool>(*request.documentFormattingProvider) or not std::get<bool>(*request.
    documentFormattingProvider) or not request.documentRangeFormattingProvider.has_value() or not
    std::holds_alternative<bool>(*request.documentRangeFormattingProvider) or not std::get<bool>(*
    request.documentRangeFormattingProvider) or not request.documentOnTypeFormattingProvider.
    has_value() or request.documentOnTypeFormattingProvider->firstTriggerCharacter not_eq "meow" or
    not request.documentOnTypeFormattingProvider->moreTriggerCharacter.has_value() or request.
    documentOnTypeFormattingProvider->moreTriggerCharacter->size() not_eq 1uz or (*request.
    documentOnTypeFormattingProvider->moreTriggerCharacter)[0uz] not_eq "nya" or not request.
    renameProvider.has_value() or not std::holds_alternative<bool>(*request.renameProvider) or not
    std::get<bool>(*request.renameProvider) or not request.foldingRangeProvider.has_value() or not
    std::holds_alternative<bool>(*request.foldingRangeProvider) or not std::get<bool>(*request.
    foldingRangeProvider) or not request.executeCommandProvider.has_value() or not request.
    executeCommandProvider->workDoneProgress.has_value() or not *request.executeCommandProvider->
    workDoneProgress or not request.executeCommandProvider->commands.empty() or not request.
    selectionRangeProvider.has_value() or not std::holds_alternative<bool>(*request.
    selectionRangeProvider) or not std::get<bool>(*request.selectionRangeProvider) or not request.
    linkedEditingRangeProvider.has_value() or not std::holds_alternative<bool>(*request.
    linkedEditingRangeProvider) or not std::get<bool>(*request.linkedEditingRangeProvider) or not
    request.callHierarchyProvider.has_value() or not std::holds_alternative<bool>(*request.
    callHierarchyProvider) or not std::get<bool>(*request.callHierarchyProvider) or not request.
    semanticTokensProvider.has_value() or not std::holds_alternative<Eura::SemanticTokensOptions>(*
    request.semanticTokensProvider))
        return false;
    const Eura::SemanticTokensOptions& semanticTokensProvider = std::get<Eura::
    SemanticTokensOptions>(*request.semanticTokensProvider);
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
    if(not full.delta.has_value() or not *full.delta or not request.monikerProvider.has_value() or
    not std::holds_alternative<bool>(*request.monikerProvider) or not std::get<bool>(*request.
    monikerProvider) or not request.typeHierarchyProvider.has_value() or not std::holds_alternative
    <bool>(*request.typeHierarchyProvider) or not std::get<bool>(*request.typeHierarchyProvider) or
    not request.inlineValueProvider.has_value() or not std::holds_alternative<bool>(*request.
    inlineValueProvider) or not std::get<bool>(*request.inlineValueProvider) or not request.
    inlayHintProvider.has_value() or not std::holds_alternative<bool>(*request.inlayHintProvider)
    or not std::get<bool>(*request.inlayHintProvider) or not request.diagnosticProvider.has_value()
    or not std::holds_alternative<Eura::DiagnosticOptions>(*request.diagnosticProvider))
        return false;
    const Eura::DiagnosticOptions& diagnosticProvider = std::get<Eura::DiagnosticOptions>(*request.
    diagnosticProvider);
    if(not diagnosticProvider.workDoneProgress.has_value() or not *diagnosticProvider.
    workDoneProgress or not diagnosticProvider.identifier.has_value() or *diagnosticProvider.
    identifier not_eq "meow" or not diagnosticProvider.interFileDependencies or not
    diagnosticProvider.workspaceDiagnostics or not request.workspaceSymbolProvider.has_value() or
    not std::holds_alternative<bool>(*request.workspaceSymbolProvider) or not std::get<bool>(*
    request.workspaceSymbolProvider) or not request.inlineCompletionProvider.has_value() or not std
    ::holds_alternative<bool>(*request.inlineCompletionProvider) or not std::get<bool>(*request.
    inlineCompletionProvider) or request.workspace.has_value() or not request.experimental.
    has_value())
        return false;
    Eura::Message message;
    from_json(*request.experimental, message);
    if(message.jsonrpc not_eq "2.0")
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