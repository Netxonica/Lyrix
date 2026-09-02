// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/InitializeParams.hpp"
#include "Eura/Message.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"workDoneToken\":\"meow\",\"processId\":67,\"clientInfo\":{\"name\":\"meow\",\"version\":\"6.7\"},\"locale\":\"nya\",\"rootPath\":\"uwu\",\"rootUri\":\"skibidi\",\"initializationOptions\":{\"jsonrpc\":\"2.0\"},\"capabilities\":{\"workspace\":{\"applyEdit\":true,\"workspaceEdit\":{\"documentChanges\":true,\"resourceOperations\":[\"meow\"],\"failureHandling\":\"abort\",\"normalizesLineEndings\":true,\"changeAnnotationSupport\":{\"groupsOnLabel\":true},\"metadataSupport\":true,\"snippetEditSupport\":true},\"didChangeConfiguration\":{\"dynamicRegistration\":true},\"didChangeWatchedFiles\":{\"dynamicRegistration\":true,\"relativePatternSupport\":true},\"symbol\":{\"dynamicRegistration\":true,\"symbolKind\":{\"valueSet\":[1]},\"tagSupport\":{\"valueSet\":[1]},\"resolveSupport\":{\"properties\":[\"meow\"]}},\"executeCommand\":{\"dynamicRegistration\":true},\"workspaceFolders\":true,\"configuration\":true,\"semanticTokens\":{\"refreshSupport\":true},\"codeLens\":{\"refreshSupport\":true},\"fileOperations\":{\"dynamicRegistration\":true,\"didCreate\":true,\"willCreate\":true,\"didRename\":true,\"willRename\":true,\"didDelete\":true,\"willDelete\":true},\"inlineValue\":{\"refreshSupport\":true},\"inlayHint\":{\"refreshSupport\":true},\"diagnostics\":{\"refreshSupport\":true},\"foldingRange\":{\"refreshSupport\":true},\"textDocumentContent\":{\"dynamicRegistration\":true}},\"textDocument\":{\"synchronization\":{\"dynamicRegistration\":true,\"willSave\":true,\"willSaveWaitUntil\":true,\"didSave\":true},\"filters\":{\"relativePatternSupport\":true},\"completion\":{\"dynamicRegistration\":true,\"completionItem\":{\"snippetSupport\":true,\"commitCharactersSupport\":true,\"documentationFormat\":[\"markdown\"],\"deprecatedSupport\":true,\"preselectSupport\":true,\"tagSupport\":{\"valueSet\":[1]},\"insertReplaceSupport\":true,\"resolveSupport\":{\"properties\":[\"meow\"]},\"insertTextModeSupport\":{\"valueSet\":[2]},\"labelDetailsSupport\":true},\"completionItemKind\":{\"valueSet\":[3]},\"contextSupport\":true,\"insertTextMode\":2,\"completionList\":{\"itemDefaults\":[\"meow\"],\"applyKindSupport\":true}},\"hover\":{\"dynamicRegistration\":true,\"contentFormat\":[\"markdown\"]},\"signatureHelp\":{\"dynamicRegistration\":true,\"signatureInformation\":{\"documentationFormat\":[\"markdown\"],\"parameterInformation\":{\"labelOffsetSupport\":true},\"activeParameterSupport\":true,\"noActiveParameterSupport\":true},\"contextSupport\":true},\"declaration\":{\"dynamicRegistration\":true,\"linkSupport\":true},\"definition\":{\"dynamicRegistration\":true,\"linkSupport\":true},\"typeDefinition\":{\"dynamicRegistration\":true,\"linkSupport\":true},\"implementation\":{\"dynamicRegistration\":true,\"linkSupport\":true},\"references\":{\"dynamicRegistration\":true},\"documentHighlight\":{\"dynamicRegistration\":true},\"documentSymbol\":{\"dynamicRegistration\":true,\"symbolKind\":{\"valueSet\":[1]},\"hierarchicalDocumentSymbolSupport\":true,\"tagSupport\":{\"valueSet\":[1]},\"labelSupport\":true},\"codeAction\":{\"dynamicRegistration\":true,\"codeActionLiteralSupport\":{\"codeActionKind\":{\"valueSet\":[\"source\"]}},\"isPreferredSupport\":true,\"disabledSupport\":true,\"dataSupport\":true,\"resolveSupport\":{\"properties\":[\"meow\"]},\"honorsChangeAnnotations\":true,\"documentationSupport\":true,\"tagSupport\":{\"valueSet\":[1]}},\"codeLens\":{\"dynamicRegistration\":true,\"resolveSupport\":{\"properties\":[\"meow\"]}},\"documentLink\":{\"dynamicRegistration\":true,\"tooltipSupport\":true},\"colorProvider\":{\"dynamicRegistration\":true},\"formatting\":{\"dynamicRegistration\":true},\"rangeFormatting\":{\"dynamicRegistration\":true,\"rangesSupport\":true},\"onTypeFormatting\":{\"dynamicRegistration\":true},\"rename\":{\"dynamicRegistration\":true,\"prepareSupport\":true,\"prepareSupportDefaultBehavior\":1,\"honorsChangeAnnotations\":true},\"publishDiagnostics\":{\"relatedInformation\":true,\"tagSupport\":{\"valueSet\":[2]},\"versionSupport\":true,\"codeDescriptionSupport\":true,\"dataSupport\":true},\"foldingRange\":{\"dynamicRegistration\":true,\"rangeLimit\":67,\"lineFoldingOnly\":true,\"foldingRangeKind\":{\"valueSet\":[\"comment\"]},\"foldingRange\":{\"collapsedText\":true}},\"selectionRange\":{\"dynamicRegistration\":true},\"linkedEditingRange\":{\"dynamicRegistration\":true},\"callHierarchy\":{\"dynamicRegistration\":true},\"semanticTokens\":{\"dynamicRegistration\":true,\"requests\":{\"range\":{},\"full\":{\"delta\":true}},\"tokenTypes\":[\"meow\"],\"tokenModifiers\":[\"nya\"],\"formats\":[\"relative\"],\"overlappingTokenSupport\":true,\"multilineTokenSupport\":true,\"serverCancelSupport\":true,\"augmentsSyntaxTokens\":true},\"moniker\":{\"dynamicRegistration\":true},\"typeHierarchy\":{\"dynamicRegistration\":true},\"inlineValue\":{\"dynamicRegistration\":true},\"inlayHint\":{\"dynamicRegistration\":true,\"resolveSupport\":{\"properties\":[\"meow\"]}},\"diagnostic\":{\"dynamicRegistration\":true,\"relatedDocumentSupport\":true,\"relatedInformation\":true,\"tagSupport\":{\"valueSet\":[2]},\"codeDescriptionSupport\":true,\"markupMessageSupport\":true,\"dataSupport\":true},\"inlineCompletion\":{\"dynamicRegistration\":true}},\"notebookDocument\":{\"synchronization\":{\"dynamicRegistration\":true,\"executionSummarySupport\":true}},\"window\":{\"workDoneProgress\":true,\"showMessage\":{\"messageActionItem\":{\"additionalPropertiesSupport\":true}},\"showDocument\":{\"support\":true}},\"general\":{\"staleRequestSupport\":{\"cancel\":true,\"retryOnContentModified\":[\"meow\"]},\"regularExpressions\":{\"engine\":\"ES2020\",\"version\":\"6.7\"},\"markdown\":{\"parser\":\"lyrix\",\"version\":\"67\",\"allowedTags\":[\"meow\",\"nya\"]},\"positionEncodings\":[\"utf-8\"]},\"experimental\":{\"jsonrpc\":\"2.0\"}},\"trace\":\"off\",\"workspaceFolders\":[{\"uri\":\"meow.extension\",\"name\":\"meow nya\"}]}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::InitializeParams request;
    Eura::from_json(root, request);
    if(not request.workDoneToken.has_value() or not std::holds_alternative<std::string>(*request.
    workDoneToken) or std::get<std::string>(*request.workDoneToken) not_eq "meow" or not std::
    holds_alternative<std::int32_t>(request.processId) or std::get<std::int32_t>(request.processId)
    not_eq 67 or not request.clientInfo.has_value() or request.clientInfo->name not_eq "meow" or
    not request.clientInfo->version.has_value() or *request.clientInfo->version not_eq "6.7" or not
    request.locale.has_value() or *request.locale not_eq "nya" or not request.rootPath.has_value()
    or not std::holds_alternative<std::string>(*request.rootPath) or std::get<std::string>(*request
    .rootPath) not_eq "uwu" or not std::holds_alternative<Eura::DocumentUri>(request.rootUri) or
    std::get<Eura::DocumentUri>(request.rootUri) not_eq "skibidi" or not request.
    initializationOptions.has_value())
        return false;
    Eura::Message message;
    from_json(*request.initializationOptions, message);
    if(message.jsonrpc not_eq "2.0" or not request.capabilities.workspace.has_value() or not
    request.capabilities.workspace->applyEdit.has_value() or not *request.capabilities.workspace->
    applyEdit or not request.capabilities.workspace->workspaceEdit.has_value() or not request.
    capabilities.workspace->workspaceEdit->documentChanges.has_value() or not *request.capabilities
    .workspace->workspaceEdit->documentChanges or not request.capabilities.workspace->workspaceEdit
    ->resourceOperations.has_value() or request.capabilities.workspace->workspaceEdit->
    resourceOperations->size() not_eq 1uz or (*request.capabilities.workspace->workspaceEdit->
    resourceOperations)[0uz] not_eq "meow" or not request.capabilities.workspace->workspaceEdit->
    failureHandling.has_value() or *request.capabilities.workspace->workspaceEdit->failureHandling
    not_eq "abort" or not request.capabilities.workspace->workspaceEdit->normalizesLineEndings.
    has_value() or not *request.capabilities.workspace->workspaceEdit->normalizesLineEndings or not
    request.capabilities.workspace->workspaceEdit->changeAnnotationSupport.has_value() or not
    request.capabilities.workspace->workspaceEdit->changeAnnotationSupport->groupsOnLabel.has_value
    () or not *request.capabilities.workspace->workspaceEdit->changeAnnotationSupport->
    groupsOnLabel or not request.capabilities.workspace->workspaceEdit->metadataSupport.has_value()
    or not *request.capabilities.workspace->workspaceEdit->metadataSupport or not request.
    capabilities.workspace->workspaceEdit->snippetEditSupport.has_value() or not *request.
    capabilities.workspace->workspaceEdit->snippetEditSupport or not request.capabilities.workspace
    ->didChangeConfiguration.has_value() or not request.capabilities.workspace->
    didChangeConfiguration->dynamicRegistration.has_value() or not *request.capabilities.workspace
    ->didChangeConfiguration->dynamicRegistration or not request.capabilities.workspace->
    didChangeWatchedFiles.has_value() or not request.capabilities.workspace->didChangeWatchedFiles
    ->dynamicRegistration.has_value() or not *request.capabilities.workspace->didChangeWatchedFiles
    ->dynamicRegistration or not request.capabilities.workspace->didChangeWatchedFiles->
    relativePatternSupport.has_value() or not *request.capabilities.workspace->
    didChangeWatchedFiles->relativePatternSupport or not request.capabilities.workspace->symbol.
    has_value() or not request.capabilities.workspace->symbol->dynamicRegistration.has_value() or
    not *request.capabilities.workspace->symbol->dynamicRegistration or not request.capabilities.
    workspace->symbol->symbolKind.has_value() or not request.capabilities.workspace->symbol->
    symbolKind->valueSet.has_value() or request.capabilities.workspace->symbol->symbolKind->
    valueSet->size() not_eq 1uz or (*request.capabilities.workspace->symbol->symbolKind->valueSet)[
    0uz] not_eq Eura::SymbolKind::File or not request.capabilities.workspace->symbol->tagSupport.
    has_value() or request.capabilities.workspace->symbol->tagSupport->valueSet.size() not_eq 1uz
    or request.capabilities.workspace->symbol->tagSupport->valueSet[0uz] not_eq Eura::SymbolTag::
    Deprecated or not request.capabilities.workspace->symbol->resolveSupport.has_value() or request
    .capabilities.workspace->symbol->resolveSupport->properties.size() not_eq 1uz or request.
    capabilities.workspace->symbol->resolveSupport->properties[0uz] not_eq "meow" or not request.
    capabilities.workspace->executeCommand.has_value() or not request.capabilities.workspace->
    executeCommand->dynamicRegistration.has_value() or not *request.capabilities.workspace->
    executeCommand->dynamicRegistration or not request.capabilities.workspace->workspaceFolders.
    has_value() or not *request.capabilities.workspace->workspaceFolders or not request.
    capabilities.workspace->configuration.has_value() or not *request.capabilities.workspace->
    configuration or not request.capabilities.workspace->semanticTokens.has_value() or not request.
    capabilities.workspace->semanticTokens->refreshSupport.has_value() or not *request.capabilities
    .workspace->semanticTokens->refreshSupport or not request.capabilities.workspace->codeLens.
    has_value() or not request.capabilities.workspace->codeLens->refreshSupport.has_value() or not
    *request.capabilities.workspace->codeLens->refreshSupport or not request.capabilities.workspace
    ->fileOperations.has_value() or not request.capabilities.workspace->fileOperations->
    dynamicRegistration.has_value() or not *request.capabilities.workspace->fileOperations->
    dynamicRegistration or not request.capabilities.workspace->fileOperations->didCreate.has_value(
    ) or not *request.capabilities.workspace->fileOperations->didCreate or not request.capabilities
    .workspace->fileOperations->willCreate.has_value() or not *request.capabilities.workspace->
    fileOperations->willCreate or not request.capabilities.workspace->fileOperations->didRename.
    has_value() or not *request.capabilities.workspace->fileOperations->didRename or not request.
    capabilities.workspace->fileOperations->willRename.has_value() or not *request.capabilities.
    workspace->fileOperations->willRename or not request.capabilities.workspace->fileOperations->
    didDelete.has_value() or not *request.capabilities.workspace->fileOperations->didDelete or not
    request.capabilities.workspace->fileOperations->willDelete.has_value() or not *request.
    capabilities.workspace->fileOperations->willDelete or not request.capabilities.workspace->
    inlineValue.has_value() or not request.capabilities.workspace->inlineValue->refreshSupport.
    has_value() or not *request.capabilities.workspace->inlineValue->refreshSupport or not request.
    capabilities.workspace->inlayHint.has_value() or not request.capabilities.workspace->inlayHint
    ->refreshSupport.has_value() or not *request.capabilities.workspace->inlayHint->refreshSupport
    or not request.capabilities.workspace->diagnostics.has_value() or not request.capabilities.
    workspace->diagnostics->refreshSupport.has_value() or not *request.capabilities.workspace->
    diagnostics->refreshSupport or not request.capabilities.workspace->foldingRange.has_value() or
    not request.capabilities.workspace->foldingRange->refreshSupport.has_value() or not *request.
    capabilities.workspace->foldingRange->refreshSupport or not request.capabilities.workspace->
    textDocumentContent.has_value() or not request.capabilities.workspace->textDocumentContent->
    dynamicRegistration.has_value() or not *request.capabilities.workspace->textDocumentContent->
    dynamicRegistration or not request.capabilities.textDocument.has_value() or not request.
    capabilities.textDocument->synchronization.has_value() or not request.capabilities.textDocument
    ->synchronization->dynamicRegistration.has_value() or not *request.capabilities.textDocument->
    synchronization->dynamicRegistration or not request.capabilities.textDocument->synchronization
    ->willSave.has_value() or not *request.capabilities.textDocument->synchronization->willSave or
    not request.capabilities.textDocument->synchronization->willSaveWaitUntil.has_value() or not *
    request.capabilities.textDocument->synchronization->willSaveWaitUntil or not request.
    capabilities.textDocument->synchronization->didSave.has_value() or not *request.capabilities.
    textDocument->synchronization->didSave or not request.capabilities.textDocument->filters.
    has_value() or not request.capabilities.textDocument->filters->relativePatternSupport.has_value
    () or not *request.capabilities.textDocument->filters->relativePatternSupport or not request.
    capabilities.textDocument->completion.has_value() or not request.capabilities.textDocument->
    completion->dynamicRegistration.has_value() or not *request.capabilities.textDocument->
    completion->dynamicRegistration or not request.capabilities.textDocument->completion->
    completionItem.has_value() or not request.capabilities.textDocument->completion->completionItem
    ->snippetSupport.has_value() or not *request.capabilities.textDocument->completion->
    completionItem->snippetSupport or not request.capabilities.textDocument->completion->
    completionItem->commitCharactersSupport.has_value() or not *request.capabilities.textDocument->
    completion->completionItem->commitCharactersSupport or not request.capabilities.textDocument->
    completion->completionItem->documentationFormat.has_value() or request.capabilities.
    textDocument->completion->completionItem->documentationFormat->size() not_eq 1uz or (*request.
    capabilities.textDocument->completion->completionItem->documentationFormat)[0uz] not_eq Eura::
    Markdown or not request.capabilities.textDocument->completion->completionItem->
    deprecatedSupport.has_value() or not *request.capabilities.textDocument->completion->
    completionItem->deprecatedSupport or not request.capabilities.textDocument->completion->
    completionItem->preselectSupport.has_value() or not *request.capabilities.textDocument->
    completion->completionItem->preselectSupport or not request.capabilities.textDocument->
    completion->completionItem->tagSupport.has_value() or request.capabilities.textDocument->
    completion->completionItem->tagSupport->valueSet.size() not_eq 1uz or request.capabilities.
    textDocument->completion->completionItem->tagSupport->valueSet[0uz] not_eq Eura::
    CompletionItemTag::Deprecated or not request.capabilities.textDocument->completion->
    completionItem->insertReplaceSupport.has_value() or not *request.capabilities.textDocument->
    completion->completionItem->insertReplaceSupport or not request.capabilities.textDocument->
    completion->completionItem->resolveSupport.has_value() or request.capabilities.textDocument->
    completion->completionItem->resolveSupport->properties.size() not_eq 1uz or request.
    capabilities.textDocument->completion->completionItem->resolveSupport->properties[0uz] not_eq
    "meow" or not request.capabilities.textDocument->completion->completionItem->
    insertTextModeSupport.has_value() or request.capabilities.textDocument->completion->
    completionItem->insertTextModeSupport->valueSet.size() not_eq 1uz or request.capabilities.
    textDocument->completion->completionItem->insertTextModeSupport->valueSet[0uz] not_eq Eura::
    InsertTextMode::AdjustIndentation or not request.capabilities.textDocument->completion->
    completionItem->labelDetailsSupport.has_value() or not *request.capabilities.textDocument->
    completion->completionItem->labelDetailsSupport or not request.capabilities.textDocument->
    completion->completionItemKind.has_value() or not request.capabilities.textDocument->completion
    ->completionItemKind->valueSet.has_value() or request.capabilities.textDocument->completion->
    completionItemKind->valueSet->size() not_eq 1uz or (*request.capabilities.textDocument->
    completion->completionItemKind->valueSet)[0uz] not_eq Eura::CompletionItemKind::Function or not
    request.capabilities.textDocument->completion->contextSupport.has_value() or not *request.
    capabilities.textDocument->completion->contextSupport or not request.capabilities.textDocument
    ->completion->insertTextMode.has_value() or *request.capabilities.textDocument->completion->
    insertTextMode not_eq Eura::InsertTextMode::AdjustIndentation or not request.capabilities.
    textDocument->completion->completionList.has_value() or not request.capabilities.textDocument->
    completion->completionList->itemDefaults.has_value() or request.capabilities.textDocument->
    completion->completionList->itemDefaults->size() not_eq 1uz or (*request.capabilities.
    textDocument->completion->completionList->itemDefaults)[0uz] not_eq "meow" or not request.
    capabilities.textDocument->completion->completionList->applyKindSupport.has_value() or not *
    request.capabilities.textDocument->completion->completionList->applyKindSupport or not request.
    capabilities.textDocument->hover.has_value() or not request.capabilities.textDocument->hover->
    dynamicRegistration.has_value() or not *request.capabilities.textDocument->hover->
    dynamicRegistration or not request.capabilities.textDocument->hover->contentFormat.has_value()
    or request.capabilities.textDocument->hover->contentFormat->size() not_eq 1uz or (*request.
    capabilities.textDocument->hover->contentFormat)[0uz] not_eq Eura::Markdown or not request.
    capabilities.textDocument->signatureHelp.has_value() or not request.capabilities.textDocument->
    signatureHelp->dynamicRegistration.has_value() or not *request.capabilities.textDocument->
    signatureHelp->dynamicRegistration or not request.capabilities.textDocument->signatureHelp->
    signatureInformation.has_value() or not request.capabilities.textDocument->signatureHelp->
    signatureInformation->documentationFormat.has_value() or request.capabilities.textDocument->
    signatureHelp->signatureInformation->documentationFormat->size() not_eq 1uz or (*request.
    capabilities.textDocument->signatureHelp->signatureInformation->documentationFormat)[0uz]
    not_eq Eura::Markdown or not request.capabilities.textDocument->signatureHelp->
    signatureInformation->parameterInformation.has_value() or not request.capabilities.textDocument
    ->signatureHelp->signatureInformation->parameterInformation->labelOffsetSupport.has_value() or
    not *request.capabilities.textDocument->signatureHelp->signatureInformation->
    parameterInformation->labelOffsetSupport or not request.capabilities.textDocument->
    signatureHelp->signatureInformation->activeParameterSupport.has_value() or not *request.
    capabilities.textDocument->signatureHelp->signatureInformation->activeParameterSupport or not
    request.capabilities.textDocument->signatureHelp->signatureInformation->
    noActiveParameterSupport.has_value() or not *request.capabilities.textDocument->signatureHelp->
    signatureInformation->noActiveParameterSupport or not request.capabilities.textDocument->
    signatureHelp->contextSupport.has_value() or not *request.capabilities.textDocument->
    signatureHelp->contextSupport or not request.capabilities.textDocument->declaration.has_value()
    or not request.capabilities.textDocument->declaration->dynamicRegistration.has_value() or not *
    request.capabilities.textDocument->declaration->dynamicRegistration or not request.capabilities
    .textDocument->declaration->linkSupport.has_value() or not *request.capabilities.textDocument->
    declaration->linkSupport or not request.capabilities.textDocument->definition.has_value() or
    not request.capabilities.textDocument->definition->dynamicRegistration.has_value() or not *
    request.capabilities.textDocument->definition->dynamicRegistration or not request.capabilities.
    textDocument->definition->linkSupport.has_value() or not *request.capabilities.textDocument->
    definition->linkSupport or not request.capabilities.textDocument->typeDefinition.has_value() or
    not request.capabilities.textDocument->typeDefinition->dynamicRegistration.has_value() or not *
    request.capabilities.textDocument->typeDefinition->dynamicRegistration or not request.
    capabilities.textDocument->typeDefinition->linkSupport.has_value() or not *request.capabilities
    .textDocument->typeDefinition->linkSupport or not request.capabilities.textDocument->
    implementation.has_value() or not request.capabilities.textDocument->implementation->
    dynamicRegistration.has_value() or not *request.capabilities.textDocument->implementation->
    dynamicRegistration or not request.capabilities.textDocument->implementation->linkSupport.
    has_value() or not *request.capabilities.textDocument->implementation->linkSupport or not
    request.capabilities.textDocument->references.has_value() or not request.capabilities.
    textDocument->references->dynamicRegistration.has_value() or not *request.capabilities.
    textDocument->references->dynamicRegistration or not request.capabilities.textDocument->
    documentHighlight.has_value() or not request.capabilities.textDocument->documentHighlight->
    dynamicRegistration.has_value() or not *request.capabilities.textDocument->documentHighlight->
    dynamicRegistration or not request.capabilities.textDocument->documentSymbol.has_value() or not
    request.capabilities.textDocument->documentSymbol->dynamicRegistration.has_value() or not *
    request.capabilities.textDocument->documentSymbol->dynamicRegistration or not request.
    capabilities.textDocument->documentSymbol->symbolKind.has_value() or not request.capabilities.
    textDocument->documentSymbol->symbolKind->valueSet.has_value() or request.capabilities.
    textDocument->documentSymbol->symbolKind->valueSet->size() not_eq 1uz or (*request.capabilities
    .textDocument->documentSymbol->symbolKind->valueSet)[0u] not_eq Eura::SymbolKind::File or not
    request.capabilities.textDocument->documentSymbol->hierarchicalDocumentSymbolSupport.has_value(
    ) or not *request.capabilities.textDocument->documentSymbol->hierarchicalDocumentSymbolSupport
    or not request.capabilities.textDocument->documentSymbol->tagSupport.has_value() or request.
    capabilities.textDocument->documentSymbol->tagSupport->valueSet.size() not_eq 1uz or request.
    capabilities.textDocument->documentSymbol->tagSupport->valueSet[0uz] not_eq Eura::SymbolTag::
    Deprecated or not request.capabilities.textDocument->documentSymbol->labelSupport.has_value()
    or not *request.capabilities.textDocument->documentSymbol->labelSupport or not request.
    capabilities.textDocument->codeAction.has_value() or not request.capabilities.textDocument->
    codeAction->dynamicRegistration.has_value() or not *request.capabilities.textDocument->
    codeAction->dynamicRegistration or not request.capabilities.textDocument->codeAction->
    codeActionLiteralSupport.has_value() or request.capabilities.textDocument->codeAction->
    codeActionLiteralSupport->codeActionKind.valueSet.size() not_eq 1uz or request.capabilities.
    textDocument->codeAction->codeActionLiteralSupport->codeActionKind.valueSet[0uz] not_eq Eura::
    Source or not request.capabilities.textDocument->codeAction->isPreferredSupport.has_value() or
    not *request.capabilities.textDocument->codeAction->isPreferredSupport or not request.
    capabilities.textDocument->codeAction->disabledSupport.has_value() or not *request.capabilities
    .textDocument->codeAction->disabledSupport or not request.capabilities.textDocument->codeAction
    ->dataSupport.has_value() or not *request.capabilities.textDocument->codeAction->dataSupport or
    not request.capabilities.textDocument->codeAction->resolveSupport.has_value() or request.
    capabilities.textDocument->codeAction->resolveSupport->properties.size() not_eq 1uz or request.
    capabilities.textDocument->codeAction->resolveSupport->properties[0uz] not_eq "meow" or not
    request.capabilities.textDocument->codeAction->honorsChangeAnnotations.has_value() or not *
    request.capabilities.textDocument->codeAction->honorsChangeAnnotations or not request.
    capabilities.textDocument->codeAction->documentationSupport.has_value() or not *request.
    capabilities.textDocument->codeAction->documentationSupport or not request.capabilities.
    textDocument->codeAction->tagSupport.has_value() or request.capabilities.textDocument->
    codeAction->tagSupport->valueSet.size() not_eq 1uz or request.capabilities.textDocument->
    codeAction->tagSupport->valueSet[0uz] not_eq Eura::CodeActionTag::LLMGenerated or not request.
    capabilities.textDocument->codeLens.has_value() or not request.capabilities.textDocument->
    codeLens->dynamicRegistration.has_value() or not *request.capabilities.textDocument->codeLens->
    dynamicRegistration or not request.capabilities.textDocument->codeLens->resolveSupport.
    has_value() or request.capabilities.textDocument->codeLens->resolveSupport->properties.size()
    not_eq 1uz or request.capabilities.textDocument->codeLens->resolveSupport->properties[0uz]
    not_eq "meow" or not request.capabilities.textDocument->documentLink.has_value() or not request
    .capabilities.textDocument->documentLink->dynamicRegistration.has_value() or not *request.
    capabilities.textDocument->documentLink->dynamicRegistration or not request.capabilities.
    textDocument->documentLink->tooltipSupport.has_value() or not *request.capabilities.
    textDocument->documentLink->tooltipSupport or not request.capabilities.textDocument->
    colorProvider.has_value() or not request.capabilities.textDocument->colorProvider->
    dynamicRegistration.has_value() or not *request.capabilities.textDocument->colorProvider->
    dynamicRegistration or not request.capabilities.textDocument->formatting.has_value() or not
    request.capabilities.textDocument->formatting->dynamicRegistration.has_value() or not *request.
    capabilities.textDocument->formatting->dynamicRegistration or not request.capabilities.
    textDocument->rangeFormatting.has_value() or not request.capabilities.textDocument->
    rangeFormatting->dynamicRegistration.has_value() or not *request.capabilities.textDocument->
    rangeFormatting->dynamicRegistration or not request.capabilities.textDocument->rangeFormatting
    ->rangesSupport.has_value() or not *request.capabilities.textDocument->rangeFormatting->
    rangesSupport or not request.capabilities.textDocument->onTypeFormatting.has_value() or not
    request.capabilities.textDocument->onTypeFormatting->dynamicRegistration.has_value() or not *
    request.capabilities.textDocument->onTypeFormatting->dynamicRegistration or not request.
    capabilities.textDocument->rename.has_value() or not request.capabilities.textDocument->rename
    ->dynamicRegistration.has_value() or not *request.capabilities.textDocument->rename->
    dynamicRegistration or not request.capabilities.textDocument->rename->prepareSupport.has_value(
    ) or not *request.capabilities.textDocument->rename->prepareSupport or not request.capabilities
    .textDocument->rename->prepareSupportDefaultBehavior.has_value() or *request.capabilities.
    textDocument->rename->prepareSupportDefaultBehavior not_eq Eura::PrepareSupportDefaultBehavior
    ::Identifier or not request.capabilities.textDocument->rename->honorsChangeAnnotations.
    has_value() or not *request.capabilities.textDocument->rename->honorsChangeAnnotations or not
    request.capabilities.textDocument->publishDiagnostics.has_value() or not request.capabilities.
    textDocument->publishDiagnostics->relatedInformation.has_value() or not *request.capabilities.
    textDocument->publishDiagnostics->relatedInformation or not request.capabilities.textDocument->
    publishDiagnostics->tagSupport.has_value() or request.capabilities.textDocument->
    publishDiagnostics->tagSupport->valueSet.size() not_eq 1uz or request.capabilities.textDocument
    ->publishDiagnostics->tagSupport->valueSet[0uz] not_eq Eura::DiagnosticTag::Deprecated or not
    request.capabilities.textDocument->publishDiagnostics->versionSupport.has_value() or not *
    request.capabilities.textDocument->publishDiagnostics->versionSupport or not request.
    capabilities.textDocument->publishDiagnostics->codeDescriptionSupport.has_value() or not *
    request.capabilities.textDocument->publishDiagnostics->codeDescriptionSupport or not request.
    capabilities.textDocument->publishDiagnostics->dataSupport.has_value() or not *request.
    capabilities.textDocument->publishDiagnostics->dataSupport or not request.capabilities.
    textDocument->foldingRange.has_value() or not request.capabilities.textDocument->foldingRange->
    dynamicRegistration.has_value() or not *request.capabilities.textDocument->foldingRange->
    dynamicRegistration or not request.capabilities.textDocument->foldingRange->rangeLimit.
    has_value() or *request.capabilities.textDocument->foldingRange->rangeLimit not_eq 67u or not
    request.capabilities.textDocument->foldingRange->lineFoldingOnly.has_value() or not *request.
    capabilities.textDocument->foldingRange->lineFoldingOnly or not request.capabilities.
    textDocument->foldingRange->foldingRangeKind.has_value() or not request.capabilities.
    textDocument->foldingRange->foldingRangeKind->valueSet.has_value() or request.capabilities.
    textDocument->foldingRange->foldingRangeKind->valueSet->size() not_eq 1uz or (*request.
    capabilities.textDocument->foldingRange->foldingRangeKind->valueSet)[0uz] not_eq Eura::Comment
    or not request.capabilities.textDocument->foldingRange->foldingRange.has_value() or not request
    .capabilities.textDocument->foldingRange->foldingRange->collapsedText.has_value() or not *
    request.capabilities.textDocument->foldingRange->foldingRange->collapsedText or not request.
    capabilities.textDocument->selectionRange.has_value() or not request.capabilities.textDocument
    ->selectionRange->dynamicRegistration.has_value() or not *request.capabilities.textDocument->
    selectionRange->dynamicRegistration or not request.capabilities.textDocument->
    linkedEditingRange.has_value() or not request.capabilities.textDocument->linkedEditingRange->
    dynamicRegistration.has_value() or not *request.capabilities.textDocument->linkedEditingRange->
    dynamicRegistration or not request.capabilities.textDocument->callHierarchy.has_value() or not
    request.capabilities.textDocument->callHierarchy->dynamicRegistration.has_value() or not *
    request.capabilities.textDocument->callHierarchy->dynamicRegistration or not request.
    capabilities.textDocument->semanticTokens.has_value() or not request.capabilities.textDocument
    ->semanticTokens->dynamicRegistration.has_value() or not *request.capabilities.textDocument->
    semanticTokens->dynamicRegistration or not request.capabilities.textDocument->semanticTokens->
    requests.range.has_value() or not std::holds_alternative<Eura::Empty>(*request.capabilities.
    textDocument->semanticTokens->requests.range) or not request.capabilities.textDocument->
    semanticTokens->requests.full.has_value() or not std::holds_alternative<Eura::
    ClientSemanticTokensRequestFullDelta>(*request.capabilities.textDocument->semanticTokens->
    requests.full))
        return false;
    const Eura::ClientSemanticTokensRequestFullDelta& delta = std::get<Eura::
    ClientSemanticTokensRequestFullDelta>(*request.capabilities.textDocument->semanticTokens->
    requests.full);
    if(not delta.delta.has_value() or not *delta.delta or request.capabilities.textDocument->
    semanticTokens->tokenTypes.size() not_eq 1uz or request.capabilities.textDocument->
    semanticTokens->tokenTypes[0uz] not_eq "meow" or request.capabilities.textDocument->
    semanticTokens->tokenModifiers.size() not_eq 1uz or request.capabilities.textDocument->
    semanticTokens->tokenModifiers[0uz] not_eq "nya" or request.capabilities.textDocument->
    semanticTokens->formats.size() not_eq 1uz or request.capabilities.textDocument->semanticTokens
    ->formats[0uz] not_eq Eura::Relative or not request.capabilities.textDocument->semanticTokens->
    overlappingTokenSupport.has_value() or not *request.capabilities.textDocument->semanticTokens->
    overlappingTokenSupport or not request.capabilities.textDocument->semanticTokens->
    multilineTokenSupport.has_value() or not *request.capabilities.textDocument->semanticTokens->
    multilineTokenSupport or not request.capabilities.textDocument->semanticTokens->
    serverCancelSupport.has_value() or not *request.capabilities.textDocument->semanticTokens->
    serverCancelSupport or not request.capabilities.textDocument->semanticTokens->
    augmentsSyntaxTokens.has_value() or not *request.capabilities.textDocument->semanticTokens->
    augmentsSyntaxTokens or not request.capabilities.textDocument->moniker.has_value() or not
    request.capabilities.textDocument->moniker->dynamicRegistration.has_value() or not *request.
    capabilities.textDocument->moniker->dynamicRegistration or not request.capabilities.
    textDocument->typeHierarchy.has_value() or not request.capabilities.textDocument->typeHierarchy
    ->dynamicRegistration.has_value() or not *request.capabilities.textDocument->typeHierarchy->
    dynamicRegistration or not request.capabilities.textDocument->inlineValue.has_value() or not
    request.capabilities.textDocument->inlineValue->dynamicRegistration.has_value() or not *request
    .capabilities.textDocument->inlineValue->dynamicRegistration or not request.capabilities.
    textDocument->inlayHint.has_value() or not request.capabilities.textDocument->inlayHint->
    dynamicRegistration.has_value() or not *request.capabilities.textDocument->inlayHint->
    dynamicRegistration or not request.capabilities.textDocument->inlayHint->resolveSupport.
    has_value() or request.capabilities.textDocument->inlayHint->resolveSupport->properties.size()
    not_eq 1uz or request.capabilities.textDocument->inlayHint->resolveSupport->properties[0uz]
    not_eq "meow" or not request.capabilities.textDocument->diagnostic.has_value() or not request.
    capabilities.textDocument->diagnostic->dynamicRegistration.has_value() or not *request.
    capabilities.textDocument->diagnostic->dynamicRegistration or not request.capabilities.
    textDocument->diagnostic->relatedDocumentSupport.has_value() or not *request.capabilities.
    textDocument->diagnostic->relatedDocumentSupport or not request.capabilities.textDocument->
    diagnostic->relatedInformation.has_value() or not *request.capabilities.textDocument->
    diagnostic->relatedInformation or not request.capabilities.textDocument->diagnostic->tagSupport
    .has_value() or request.capabilities.textDocument->diagnostic->tagSupport->valueSet.size()
    not_eq 1uz or request.capabilities.textDocument->diagnostic->tagSupport->valueSet[0uz] not_eq
    Eura::DiagnosticTag::Deprecated or not request.capabilities.textDocument->diagnostic->
    codeDescriptionSupport.has_value() or not *request.capabilities.textDocument->diagnostic->
    codeDescriptionSupport or not request.capabilities.textDocument->diagnostic->
    markupMessageSupport.has_value() or not *request.capabilities.textDocument->diagnostic->
    markupMessageSupport or not request.capabilities.textDocument->diagnostic->dataSupport.
    has_value() or not *request.capabilities.textDocument->diagnostic->dataSupport or not request.
    capabilities.textDocument->inlineCompletion.has_value() or not request.capabilities.
    textDocument->inlineCompletion->dynamicRegistration.has_value() or not *request.capabilities.
    textDocument->inlineCompletion->dynamicRegistration or not request.capabilities.
    notebookDocument.has_value() or not request.capabilities.notebookDocument->synchronization.
    dynamicRegistration.has_value() or not *request.capabilities.notebookDocument->synchronization.
    dynamicRegistration or not request.capabilities.notebookDocument->synchronization.
    executionSummarySupport.has_value() or not *request.capabilities.notebookDocument->
    synchronization.executionSummarySupport or not request.capabilities.window.has_value() or not
    request.capabilities.window->workDoneProgress.has_value() or not *request.capabilities.window->
    workDoneProgress or not request.capabilities.window->showMessage.has_value() or not request.
    capabilities.window->showMessage->messageActionItem.has_value() or not request.capabilities.
    window->showMessage->messageActionItem->additionalPropertiesSupport.has_value() or not *request
    .capabilities.window->showMessage->messageActionItem->additionalPropertiesSupport or not
    request.capabilities.window->showDocument.has_value() or not request.capabilities.window->
    showDocument->support or not request.capabilities.general.has_value() or not request.
    capabilities.general->staleRequestSupport.has_value() or not request.capabilities.general->
    staleRequestSupport->cancel or request.capabilities.general->staleRequestSupport->
    retryOnContentModified.size() not_eq 1uz or request.capabilities.general->staleRequestSupport->
    retryOnContentModified[0uz] not_eq "meow" or not request.capabilities.general->
    regularExpressions.has_value() or request.capabilities.general->regularExpressions->engine
    not_eq Eura::ES2020 or request.capabilities.general->regularExpressions->version not_eq "6.7"
    or not request.capabilities.general->markdown.has_value() or request.capabilities.general->
    markdown->parser not_eq "lyrix" or not request.capabilities.general->markdown->version.
    has_value() or *request.capabilities.general->markdown->version not_eq "67" or not request.
    capabilities.general->markdown->allowedTags.has_value() or request.capabilities.general->
    markdown->allowedTags->size() not_eq 2uz or (*request.capabilities.general->markdown->
    allowedTags)[0uz] not_eq "meow" or (*request.capabilities.general->markdown->allowedTags)[1uz]
    not_eq "nya" or not request.capabilities.general->positionEncodings.has_value() or request.
    capabilities.general->positionEncodings->size() not_eq 1uz or (*request.capabilities.general->
    positionEncodings)[0uz] not_eq Eura::UTF8 or not request.capabilities.experimental.has_value()
    or not request.trace.has_value() or *request.trace not_eq Eura::Off or not request.
    workspaceFolders.has_value() or not std::holds_alternative<std::vector<Eura::WorkspaceFolder>>(
    *request.workspaceFolders))
        return false;
    const std::vector<Eura::WorkspaceFolder>& workspaceFolders = std::get<std::vector<Eura::
    WorkspaceFolder>>(*request.workspaceFolders);
    if(workspaceFolders.size() not_eq 1uz)
        return false;
    const Eura::WorkspaceFolder& workspaceFolder = workspaceFolders[0uz];
    if(workspaceFolder.uri not_eq "meow.extension" or workspaceFolder.name not_eq "meow nya")
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