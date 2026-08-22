// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/WorkspaceClientCapabilities.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"applyEdit\":true,\"workspaceEdit\":{\"documentChanges\":true,\"resourceOperations\":[\"meow\"],\"failureHandling\":\"abort\",\"normalizesLineEndings\":true,\"changeAnnotationSupport\":{\"groupsOnLabel\":true},\"metadataSupport\":true,\"snippetEditSupport\":true},\"didChangeConfiguration\":{\"dynamicRegistration\":true},\"didChangeWatchedFiles\":{\"dynamicRegistration\":true,\"relativePatternSupport\":true},\"symbol\":{\"dynamicRegistration\":true,\"symbolKind\":{\"valueSet\":[1]},\"tagSupport\":{\"valueSet\":[1]},\"resolveSupport\":{\"properties\":[\"meow\"]}},\"executeCommand\":{\"dynamicRegistration\":true},\"workspaceFolders\":true,\"configuration\":true,\"semanticTokens\":{\"refreshSupport\":true},\"codeLens\":{\"refreshSupport\":true},\"fileOperations\":{\"dynamicRegistration\":true,\"didCreate\":true,\"willCreate\":true,\"didRename\":true,\"willRename\":true,\"didDelete\":true,\"willDelete\":true},\"inlineValue\":{\"refreshSupport\":true},\"inlayHint\":{\"refreshSupport\":true},\"diagnostics\":{\"refreshSupport\":true},\"foldingRange\":{\"refreshSupport\":true},\"textDocumentContent\":{\"dynamicRegistration\":true}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::WorkspaceClientCapabilities request;
    Eura::from_json(root, request);
    if(not request.applyEdit.has_value() or not *request.applyEdit or not request.workspaceEdit.
    has_value() or not request.workspaceEdit->documentChanges.has_value() or not *request.
    workspaceEdit->documentChanges or not request.workspaceEdit->resourceOperations.has_value() or
    request.workspaceEdit->resourceOperations->size() not_eq 1uz or (*request.workspaceEdit->
    resourceOperations)[0uz] not_eq "meow" or not request.workspaceEdit->failureHandling.has_value(
    ) or *request.workspaceEdit->failureHandling not_eq "abort" or not request.workspaceEdit->
    normalizesLineEndings.has_value() or not *request.workspaceEdit->normalizesLineEndings or not
    request.workspaceEdit->changeAnnotationSupport.has_value() or not request.workspaceEdit->
    changeAnnotationSupport->groupsOnLabel.has_value() or not *request.workspaceEdit->
    changeAnnotationSupport->groupsOnLabel or not request.workspaceEdit->metadataSupport.has_value(
    ) or not *request.workspaceEdit->metadataSupport or not request.workspaceEdit->
    snippetEditSupport.has_value() or not *request.workspaceEdit->snippetEditSupport or not request
    .didChangeConfiguration.has_value() or not request.didChangeConfiguration->dynamicRegistration.
    has_value() or not *request.didChangeConfiguration->dynamicRegistration or not request.
    didChangeWatchedFiles.has_value() or not request.didChangeWatchedFiles->dynamicRegistration.
    has_value() or not *request.didChangeWatchedFiles->dynamicRegistration or not request.
    didChangeWatchedFiles->relativePatternSupport.has_value() or not *request.didChangeWatchedFiles
    ->relativePatternSupport or not request.symbol.has_value() or not request.symbol->
    dynamicRegistration.has_value() or not *request.symbol->dynamicRegistration or not request.
    symbol->symbolKind.has_value() or not request.symbol->symbolKind->valueSet.has_value() or
    request.symbol->symbolKind->valueSet->size() not_eq 1uz or (*request.symbol->symbolKind->
    valueSet)[0u] not_eq Eura::SymbolKind::File or not request.symbol->tagSupport.has_value() or
    request.symbol->tagSupport->valueSet.size() not_eq 1uz or request.symbol->tagSupport->valueSet[
    0uz] not_eq Eura::SymbolTag::Deprecated or not request.symbol->resolveSupport.has_value() or
    request.symbol->resolveSupport->properties.size() not_eq 1uz or request.symbol->resolveSupport
    ->properties[0uz] not_eq "meow" or not request.executeCommand.has_value() or not request.
    executeCommand->dynamicRegistration.has_value() or not *request.executeCommand->
    dynamicRegistration or not request.workspaceFolders.has_value() or not *request.
    workspaceFolders or not request.configuration.has_value() or not *request.configuration or not
    request.semanticTokens.has_value() or not request.semanticTokens->refreshSupport.has_value() or
    not *request.semanticTokens->refreshSupport or not request.codeLens.has_value() or not request.
    codeLens->refreshSupport.has_value() or not *request.codeLens->refreshSupport or not request.
    fileOperations.has_value() or not request.fileOperations->dynamicRegistration.has_value() or
    not *request.fileOperations->dynamicRegistration or not request.fileOperations->didCreate.
    has_value() or not *request.fileOperations->didCreate or not request.fileOperations->willCreate
    .has_value() or not *request.fileOperations->willCreate or not request.fileOperations->
    didRename.has_value() or not *request.fileOperations->didRename or not request.fileOperations->
    willRename.has_value() or not *request.fileOperations->willRename or not request.fileOperations
    ->didDelete.has_value() or not *request.fileOperations->didDelete or not request.fileOperations
    ->willDelete.has_value() or not *request.fileOperations->willDelete or not request.inlineValue.
    has_value() or not request.inlineValue->refreshSupport.has_value() or not *request.inlineValue
    ->refreshSupport or not request.inlayHint.has_value() or not request.inlayHint->refreshSupport.
    has_value() or not *request.inlayHint->refreshSupport or not request.diagnostics.has_value() or
    not request.diagnostics->refreshSupport.has_value() or not *request.diagnostics->refreshSupport
    or not request.foldingRange.has_value() or not request.foldingRange->refreshSupport.has_value()
    or not *request.foldingRange->refreshSupport or not request.textDocumentContent.has_value() or
    not request.textDocumentContent->dynamicRegistration.has_value() or not *request.
    textDocumentContent->dynamicRegistration)
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