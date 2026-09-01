// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ClientCapabilities.hpp"
#include "Eura/Message.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"workspace\":{\"applyEdit\":true,\"workspaceEdit\":{\"documentChanges\":true,\"resourceOperations\":[\"meow\"],\"failureHandling\":\"abort\",\"normalizesLineEndings\":true,\"changeAnnotationSupport\":{\"groupsOnLabel\":true},\"metadataSupport\":true,\"snippetEditSupport\":true},\"didChangeConfiguration\":{\"dynamicRegistration\":true},\"didChangeWatchedFiles\":{\"dynamicRegistration\":true,\"relativePatternSupport\":true},\"symbol\":{\"dynamicRegistration\":true,\"symbolKind\":{\"valueSet\":[1]},\"tagSupport\":{\"valueSet\":[1]},\"resolveSupport\":{\"properties\":[\"meow\"]}},\"executeCommand\":{\"dynamicRegistration\":true},\"workspaceFolders\":true,\"configuration\":true,\"semanticTokens\":{\"refreshSupport\":true},\"codeLens\":{\"refreshSupport\":true},\"fileOperations\":{\"dynamicRegistration\":true,\"didCreate\":true,\"willCreate\":true,\"didRename\":true,\"willRename\":true,\"didDelete\":true,\"willDelete\":true},\"inlineValue\":{\"refreshSupport\":true},\"inlayHint\":{\"refreshSupport\":true},\"diagnostics\":{\"refreshSupport\":true},\"foldingRange\":{\"refreshSupport\":true},\"textDocumentContent\":{\"dynamicRegistration\":true}},\"textDocument\":{\"synchronization\":{\"dynamicRegistration\":true,\"willSave\":true,\"willSaveWaitUntil\":true,\"didSave\":true},\"filters\":{\"relativePatternSupport\":true},\"completion\":{\"dynamicRegistration\":true,\"completionItem\":{\"snippetSupport\":true,\"commitCharactersSupport\":true,\"documentationFormat\":[\"markdown\"],\"deprecatedSupport\":true,\"preselectSupport\":true,\"tagSupport\":{\"valueSet\":[1]},\"insertReplaceSupport\":true,\"resolveSupport\":{\"properties\":[\"meow\"]},\"insertTextModeSupport\":{\"valueSet\":[2]},\"labelDetailsSupport\":true},\"completionItemKind\":{\"valueSet\":[3]},\"contextSupport\":true,\"insertTextMode\":2,\"completionList\":{\"itemDefaults\":[\"meow\"],\"applyKindSupport\":true}},\"hover\":{\"dynamicRegistration\":true,\"contentFormat\":[\"markdown\"]},\"signatureHelp\":{\"dynamicRegistration\":true,\"signatureInformation\":{\"documentationFormat\":[\"markdown\"],\"parameterInformation\":{\"labelOffsetSupport\":true},\"activeParameterSupport\":true,\"noActiveParameterSupport\":true},\"contextSupport\":true},\"declaration\":{\"dynamicRegistration\":true,\"linkSupport\":true},\"definition\":{\"dynamicRegistration\":true,\"linkSupport\":true},\"typeDefinition\":{\"dynamicRegistration\":true,\"linkSupport\":true},\"implementation\":{\"dynamicRegistration\":true,\"linkSupport\":true},\"references\":{\"dynamicRegistration\":true},\"documentHighlight\":{\"dynamicRegistration\":true},\"documentSymbol\":{\"dynamicRegistration\":true,\"symbolKind\":{\"valueSet\":[1]},\"hierarchicalDocumentSymbolSupport\":true,\"tagSupport\":{\"valueSet\":[1]},\"labelSupport\":true},\"codeAction\":{\"dynamicRegistration\":true,\"codeActionLiteralSupport\":{\"codeActionKind\":{\"valueSet\":[\"source\"]}},\"isPreferredSupport\":true,\"disabledSupport\":true,\"dataSupport\":true,\"resolveSupport\":{\"properties\":[\"meow\"]},\"honorsChangeAnnotations\":true,\"documentationSupport\":true,\"tagSupport\":{\"valueSet\":[1]}},\"codeLens\":{\"dynamicRegistration\":true,\"resolveSupport\":{\"properties\":[\"meow\"]}},\"documentLink\":{\"dynamicRegistration\":true,\"tooltipSupport\":true},\"colorProvider\":{\"dynamicRegistration\":true},\"formatting\":{\"dynamicRegistration\":true},\"rangeFormatting\":{\"dynamicRegistration\":true,\"rangesSupport\":true},\"onTypeFormatting\":{\"dynamicRegistration\":true},\"rename\":{\"dynamicRegistration\":true,\"prepareSupport\":true,\"prepareSupportDefaultBehavior\":1,\"honorsChangeAnnotations\":true},\"publishDiagnostics\":{\"relatedInformation\":true,\"tagSupport\":{\"valueSet\":[2]},\"versionSupport\":true,\"codeDescriptionSupport\":true,\"dataSupport\":true},\"foldingRange\":{\"dynamicRegistration\":true,\"rangeLimit\":67,\"lineFoldingOnly\":true,\"foldingRangeKind\":{\"valueSet\":[\"comment\"]},\"foldingRange\":{\"collapsedText\":true}},\"selectionRange\":{\"dynamicRegistration\":true},\"linkedEditingRange\":{\"dynamicRegistration\":true},\"callHierarchy\":{\"dynamicRegistration\":true},\"semanticTokens\":{\"dynamicRegistration\":true,\"requests\":{\"range\":{},\"full\":{\"delta\":true}},\"tokenTypes\":[\"meow\"],\"tokenModifiers\":[\"nya\"],\"formats\":[\"relative\"],\"overlappingTokenSupport\":true,\"multilineTokenSupport\":true,\"serverCancelSupport\":true,\"augmentsSyntaxTokens\":true},\"moniker\":{\"dynamicRegistration\":true},\"typeHierarchy\":{\"dynamicRegistration\":true},\"inlineValue\":{\"dynamicRegistration\":true},\"inlayHint\":{\"dynamicRegistration\":true,\"resolveSupport\":{\"properties\":[\"meow\"]}},\"diagnostic\":{\"dynamicRegistration\":true,\"relatedDocumentSupport\":true,\"relatedInformation\":true,\"tagSupport\":{\"valueSet\":[2]},\"codeDescriptionSupport\":true,\"markupMessageSupport\":true,\"dataSupport\":true},\"inlineCompletion\":{\"dynamicRegistration\":true}},\"notebookDocument\":{\"synchronization\":{\"dynamicRegistration\":true,\"executionSummarySupport\":true}},\"window\":{\"workDoneProgress\":true,\"showMessage\":{\"messageActionItem\":{\"additionalPropertiesSupport\":true}},\"showDocument\":{\"support\":true}},\"general\":{\"staleRequestSupport\":{\"cancel\":true,\"retryOnContentModified\":[\"meow\"]},\"regularExpressions\":{\"engine\":\"ES2020\",\"version\":\"6.7\"},\"markdown\":{\"parser\":\"lyrix\",\"version\":\"67\",\"allowedTags\":[\"meow\",\"nya\"]},\"positionEncodings\":[\"utf-8\"]},\"experimental\":{\"jsonrpc\":\"2.0\"}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::ClientCapabilities request;
    Eura::from_json(root, request);
    if(not request.workspace.has_value() or not request.workspace->applyEdit.has_value() or not *
    request.workspace->applyEdit or not request.workspace->workspaceEdit.has_value() or not request
    .workspace->workspaceEdit->documentChanges.has_value() or not *request.workspace->workspaceEdit
    ->documentChanges or not request.workspace->workspaceEdit->resourceOperations.has_value() or
    request.workspace->workspaceEdit->resourceOperations->size() not_eq 1uz or (*request.workspace
    ->workspaceEdit->resourceOperations)[0uz] not_eq "meow" or not request.workspace->workspaceEdit
    ->failureHandling.has_value() or *request.workspace->workspaceEdit->failureHandling not_eq
    "abort" or not request.workspace->workspaceEdit->normalizesLineEndings.has_value() or not *
    request.workspace->workspaceEdit->normalizesLineEndings or not request.workspace->workspaceEdit
    ->changeAnnotationSupport.has_value() or not request.workspace->workspaceEdit->
    changeAnnotationSupport->groupsOnLabel.has_value() or not *request.workspace->workspaceEdit->
    changeAnnotationSupport->groupsOnLabel or not request.workspace->workspaceEdit->metadataSupport
    .has_value() or not *request.workspace->workspaceEdit->metadataSupport or not request.workspace
    ->workspaceEdit->snippetEditSupport.has_value() or not *request.workspace->workspaceEdit->
    snippetEditSupport or not request.workspace->didChangeConfiguration.has_value() or not request.
    workspace->didChangeConfiguration->dynamicRegistration.has_value() or not *request.workspace->
    didChangeConfiguration->dynamicRegistration or not request.workspace->didChangeWatchedFiles.
    has_value() or not request.workspace->didChangeWatchedFiles->dynamicRegistration.has_value() or
    not *request.workspace->didChangeWatchedFiles->dynamicRegistration or not request.workspace->
    didChangeWatchedFiles->relativePatternSupport.has_value() or not *request.workspace->
    didChangeWatchedFiles->relativePatternSupport or not request.workspace->symbol.has_value() or
    not request.workspace->symbol->dynamicRegistration.has_value() or not *request.workspace->
    symbol->dynamicRegistration or not request.workspace->symbol->symbolKind.has_value() or not
    request.workspace->symbol->symbolKind->valueSet.has_value() or request.workspace->symbol->
    symbolKind->valueSet->size() not_eq 1uz or (*request.workspace->symbol->symbolKind->valueSet)[
    0uz] not_eq Eura::SymbolKind::File or not request.workspace->symbol->tagSupport.has_value() or
    request.workspace->symbol->tagSupport->valueSet.size() not_eq 1uz or request.workspace->symbol
    ->tagSupport->valueSet[0uz] not_eq Eura::SymbolTag::Deprecated or not request.workspace->symbol
    ->resolveSupport.has_value() or request.workspace->symbol->resolveSupport->properties.size()
    not_eq 1uz or request.workspace->symbol->resolveSupport->properties[0uz] not_eq "meow" or not
    request.workspace->executeCommand.has_value() or not request.workspace->executeCommand->
    dynamicRegistration.has_value() or not *request.workspace->executeCommand->dynamicRegistration
    or not request.workspace->workspaceFolders.has_value() or not *request.workspace->
    workspaceFolders or not request.workspace->configuration.has_value() or not *request.workspace
    ->configuration or not request.workspace->semanticTokens.has_value() or not request.workspace->
    semanticTokens->refreshSupport.has_value() or not *request.workspace->semanticTokens->
    refreshSupport or not request.workspace->codeLens.has_value() or not request.workspace->
    codeLens->refreshSupport.has_value() or not *request.workspace->codeLens->refreshSupport or not
    request.workspace->fileOperations.has_value() or not request.workspace->fileOperations->
    dynamicRegistration.has_value() or not *request.workspace->fileOperations->dynamicRegistration
    or not request.workspace->fileOperations->didCreate.has_value() or not *request.workspace->
    fileOperations->didCreate or not request.workspace->fileOperations->willCreate.has_value() or
    not *request.workspace->fileOperations->willCreate or not request.workspace->fileOperations->
    didRename.has_value() or not *request.workspace->fileOperations->didRename or not request.
    workspace->fileOperations->willRename.has_value() or not *request.workspace->fileOperations->
    willRename or not request.workspace->fileOperations->didDelete.has_value() or not *request.
    workspace->fileOperations->didDelete or not request.workspace->fileOperations->willDelete.
    has_value() or not *request.workspace->fileOperations->willDelete or not request.workspace->
    inlineValue.has_value() or not request.workspace->inlineValue->refreshSupport.has_value() or
    not *request.workspace->inlineValue->refreshSupport or not request.workspace->inlayHint.
    has_value() or not request.workspace->inlayHint->refreshSupport.has_value() or not *request.
    workspace->inlayHint->refreshSupport or not request.workspace->diagnostics.has_value() or not
    request.workspace->diagnostics->refreshSupport.has_value() or not *request.workspace->
    diagnostics->refreshSupport or not request.workspace->foldingRange.has_value() or not request.
    workspace->foldingRange->refreshSupport.has_value() or not *request.workspace->foldingRange->
    refreshSupport or not request.workspace->textDocumentContent.has_value() or not request.
    workspace->textDocumentContent->dynamicRegistration.has_value() or not *request.workspace->
    textDocumentContent->dynamicRegistration or not request.textDocument.has_value() or not request
    .textDocument->synchronization.has_value() or not request.textDocument->synchronization->
    dynamicRegistration.has_value() or not *request.textDocument->synchronization->
    dynamicRegistration or not request.textDocument->synchronization->willSave.has_value() or not *
    request.textDocument->synchronization->willSave or not request.textDocument->synchronization->
    willSaveWaitUntil.has_value() or not *request.textDocument->synchronization->willSaveWaitUntil
    or not request.textDocument->synchronization->didSave.has_value() or not *request.textDocument
    ->synchronization->didSave or not request.textDocument->filters.has_value() or not request.
    textDocument->filters->relativePatternSupport.has_value() or not *request.textDocument->filters
    ->relativePatternSupport or not request.textDocument->completion.has_value() or not request.
    textDocument->completion->dynamicRegistration.has_value() or not *request.textDocument->
    completion->dynamicRegistration or not request.textDocument->completion->completionItem.
    has_value() or not request.textDocument->completion->completionItem->snippetSupport.has_value()
    or not *request.textDocument->completion->completionItem->snippetSupport or not request.
    textDocument->completion->completionItem->commitCharactersSupport.has_value() or not *request.
    textDocument->completion->completionItem->commitCharactersSupport or not request.textDocument->
    completion->completionItem->documentationFormat.has_value() or request.textDocument->completion
    ->completionItem->documentationFormat->size() not_eq 1uz or (*request.textDocument->completion
    ->completionItem->documentationFormat)[0uz] not_eq Eura::Markdown or not request.textDocument->
    completion->completionItem->deprecatedSupport.has_value() or not *request.textDocument->
    completion->completionItem->deprecatedSupport or not request.textDocument->completion->
    completionItem->preselectSupport.has_value() or not *request.textDocument->completion->
    completionItem->preselectSupport or not request.textDocument->completion->completionItem->
    tagSupport.has_value() or request.textDocument->completion->completionItem->tagSupport->
    valueSet.size() not_eq 1uz or request.textDocument->completion->completionItem->tagSupport->
    valueSet[0uz] not_eq Eura::CompletionItemTag::Deprecated or not request.textDocument->
    completion->completionItem->insertReplaceSupport.has_value() or not *request.textDocument->
    completion->completionItem->insertReplaceSupport or not request.textDocument->completion->
    completionItem->resolveSupport.has_value() or request.textDocument->completion->completionItem
    ->resolveSupport->properties.size() not_eq 1uz or request.textDocument->completion->
    completionItem->resolveSupport->properties[0uz] not_eq "meow" or not request.textDocument->
    completion->completionItem->insertTextModeSupport.has_value() or request.textDocument->
    completion->completionItem->insertTextModeSupport->valueSet.size() not_eq 1uz or request.
    textDocument->completion->completionItem->insertTextModeSupport->valueSet[0uz] not_eq Eura::
    InsertTextMode::AdjustIndentation or not request.textDocument->completion->completionItem->
    labelDetailsSupport.has_value() or not *request.textDocument->completion->completionItem->
    labelDetailsSupport or not request.textDocument->completion->completionItemKind.has_value() or
    not request.textDocument->completion->completionItemKind->valueSet.has_value() or request.
    textDocument->completion->completionItemKind->valueSet->size() not_eq 1uz or (*request.
    textDocument->completion->completionItemKind->valueSet)[0uz] not_eq Eura::CompletionItemKind::
    Function or not request.textDocument->completion->contextSupport.has_value() or not *request.
    textDocument->completion->contextSupport or not request.textDocument->completion->
    insertTextMode.has_value() or *request.textDocument->completion->insertTextMode not_eq Eura::
    InsertTextMode::AdjustIndentation or not request.textDocument->completion->completionList.
    has_value() or not request.textDocument->completion->completionList->itemDefaults.has_value()
    or request.textDocument->completion->completionList->itemDefaults->size() not_eq 1uz or (*
    request.textDocument->completion->completionList->itemDefaults)[0uz] not_eq "meow" or not
    request.textDocument->completion->completionList->applyKindSupport.has_value() or not *request.
    textDocument->completion->completionList->applyKindSupport or not request.textDocument->hover.
    has_value() or not request.textDocument->hover->dynamicRegistration.has_value() or not *request
    .textDocument->hover->dynamicRegistration or not request.textDocument->hover->contentFormat.
    has_value() or request.textDocument->hover->contentFormat->size() not_eq 1uz or (*request.
    textDocument->hover->contentFormat)[0uz] not_eq Eura::Markdown or not request.textDocument->
    signatureHelp.has_value() or not request.textDocument->signatureHelp->dynamicRegistration.
    has_value() or not *request.textDocument->signatureHelp->dynamicRegistration or not request.
    textDocument->signatureHelp->signatureInformation.has_value() or not request.textDocument->
    signatureHelp->signatureInformation->documentationFormat.has_value() or request.textDocument->
    signatureHelp->signatureInformation->documentationFormat->size() not_eq 1uz or (*request.
    textDocument->signatureHelp->signatureInformation->documentationFormat)[0uz] not_eq Eura::
    Markdown or not request.textDocument->signatureHelp->signatureInformation->parameterInformation
    .has_value() or not request.textDocument->signatureHelp->signatureInformation->
    parameterInformation->labelOffsetSupport.has_value() or not *request.textDocument->
    signatureHelp->signatureInformation->parameterInformation->labelOffsetSupport or not request.
    textDocument->signatureHelp->signatureInformation->activeParameterSupport.has_value() or not *
    request.textDocument->signatureHelp->signatureInformation->activeParameterSupport or not
    request.textDocument->signatureHelp->signatureInformation->noActiveParameterSupport.has_value()
    or not *request.textDocument->signatureHelp->signatureInformation->noActiveParameterSupport or
    not request.textDocument->signatureHelp->contextSupport.has_value() or not *request.
    textDocument->signatureHelp->contextSupport or not request.textDocument->declaration.has_value(
    ) or not request.textDocument->declaration->dynamicRegistration.has_value() or not *request.
    textDocument->declaration->dynamicRegistration or not request.textDocument->declaration->
    linkSupport.has_value() or not *request.textDocument->declaration->linkSupport or not request.
    textDocument->definition.has_value() or not request.textDocument->definition->
    dynamicRegistration.has_value() or not *request.textDocument->definition->dynamicRegistration
    or not request.textDocument->definition->linkSupport.has_value() or not *request.textDocument->
    definition->linkSupport or not request.textDocument->typeDefinition.has_value() or not request.
    textDocument->typeDefinition->dynamicRegistration.has_value() or not *request.textDocument->
    typeDefinition->dynamicRegistration or not request.textDocument->typeDefinition->linkSupport.
    has_value() or not *request.textDocument->typeDefinition->linkSupport or not request.
    textDocument->implementation.has_value() or not request.textDocument->implementation->
    dynamicRegistration.has_value() or not *request.textDocument->implementation->
    dynamicRegistration or not request.textDocument->implementation->linkSupport.has_value() or not
    *request.textDocument->implementation->linkSupport or not request.textDocument->references.
    has_value() or not request.textDocument->references->dynamicRegistration.has_value() or not *
    request.textDocument->references->dynamicRegistration or not request.textDocument->
    documentHighlight.has_value() or not request.textDocument->documentHighlight->
    dynamicRegistration.has_value() or not *request.textDocument->documentHighlight->
    dynamicRegistration or not request.textDocument->documentSymbol.has_value() or not request.
    textDocument->documentSymbol->dynamicRegistration.has_value() or not *request.textDocument->
    documentSymbol->dynamicRegistration or not request.textDocument->documentSymbol->symbolKind.
    has_value() or not request.textDocument->documentSymbol->symbolKind->valueSet.has_value() or
    request.textDocument->documentSymbol->symbolKind->valueSet->size() not_eq 1uz or (*request.
    textDocument->documentSymbol->symbolKind->valueSet)[0u] not_eq Eura::SymbolKind::File or not
    request.textDocument->documentSymbol->hierarchicalDocumentSymbolSupport.has_value() or not *
    request.textDocument->documentSymbol->hierarchicalDocumentSymbolSupport or not request.
    textDocument->documentSymbol->tagSupport.has_value() or request.textDocument->documentSymbol->
    tagSupport->valueSet.size() not_eq 1uz or request.textDocument->documentSymbol->tagSupport->
    valueSet[0uz] not_eq Eura::SymbolTag::Deprecated or not request.textDocument->documentSymbol->
    labelSupport.has_value() or not *request.textDocument->documentSymbol->labelSupport or not
    request.textDocument->codeAction.has_value() or not request.textDocument->codeAction->
    dynamicRegistration.has_value() or not *request.textDocument->codeAction->dynamicRegistration
    or not request.textDocument->codeAction->codeActionLiteralSupport.has_value() or request.
    textDocument->codeAction->codeActionLiteralSupport->codeActionKind.valueSet.size() not_eq 1uz
    or request.textDocument->codeAction->codeActionLiteralSupport->codeActionKind.valueSet[0uz]
    not_eq Eura::Source or not request.textDocument->codeAction->isPreferredSupport.has_value() or
    not *request.textDocument->codeAction->isPreferredSupport or not request.textDocument->
    codeAction->disabledSupport.has_value() or not *request.textDocument->codeAction->
    disabledSupport or not request.textDocument->codeAction->dataSupport.has_value() or not *
    request.textDocument->codeAction->dataSupport or not request.textDocument->codeAction->
    resolveSupport.has_value() or request.textDocument->codeAction->resolveSupport->properties.size
    () not_eq 1uz or request.textDocument->codeAction->resolveSupport->properties[0uz] not_eq
    "meow" or not request.textDocument->codeAction->honorsChangeAnnotations.has_value() or not *
    request.textDocument->codeAction->honorsChangeAnnotations or not request.textDocument->
    codeAction->documentationSupport.has_value() or not *request.textDocument->codeAction->
    documentationSupport or not request.textDocument->codeAction->tagSupport.has_value() or request
    .textDocument->codeAction->tagSupport->valueSet.size() not_eq 1uz or request.textDocument->
    codeAction->tagSupport->valueSet[0uz] not_eq Eura::CodeActionTag::LLMGenerated or not request.
    textDocument->codeLens.has_value() or not request.textDocument->codeLens->dynamicRegistration.
    has_value() or not *request.textDocument->codeLens->dynamicRegistration or not request.
    textDocument->codeLens->resolveSupport.has_value() or request.textDocument->codeLens->
    resolveSupport->properties.size() not_eq 1uz or request.textDocument->codeLens->resolveSupport
    ->properties[0uz] not_eq "meow" or not request.textDocument->documentLink.has_value() or not
    request.textDocument->documentLink->dynamicRegistration.has_value() or not *request.
    textDocument->documentLink->dynamicRegistration or not request.textDocument->documentLink->
    tooltipSupport.has_value() or not *request.textDocument->documentLink->tooltipSupport or not
    request.textDocument->colorProvider.has_value() or not request.textDocument->colorProvider->
    dynamicRegistration.has_value() or not *request.textDocument->colorProvider->
    dynamicRegistration or not request.textDocument->formatting.has_value() or not request.
    textDocument->formatting->dynamicRegistration.has_value() or not *request.textDocument->
    formatting->dynamicRegistration or not request.textDocument->rangeFormatting.has_value() or not
    request.textDocument->rangeFormatting->dynamicRegistration.has_value() or not *request.
    textDocument->rangeFormatting->dynamicRegistration or not request.textDocument->rangeFormatting
    ->rangesSupport.has_value() or not *request.textDocument->rangeFormatting->rangesSupport or not
    request.textDocument->onTypeFormatting.has_value() or not request.textDocument->
    onTypeFormatting->dynamicRegistration.has_value() or not *request.textDocument->
    onTypeFormatting->dynamicRegistration or not request.textDocument->rename.has_value() or not
    request.textDocument->rename->dynamicRegistration.has_value() or not *request.textDocument->
    rename->dynamicRegistration or not request.textDocument->rename->prepareSupport.has_value() or
    not *request.textDocument->rename->prepareSupport or not request.textDocument->rename->
    prepareSupportDefaultBehavior.has_value() or *request.textDocument->rename->
    prepareSupportDefaultBehavior not_eq Eura::PrepareSupportDefaultBehavior::Identifier or not
    request.textDocument->rename->honorsChangeAnnotations.has_value() or not *request.textDocument
    ->rename->honorsChangeAnnotations or not request.textDocument->publishDiagnostics.has_value()
    or not request.textDocument->publishDiagnostics->relatedInformation.has_value() or not *request
    .textDocument->publishDiagnostics->relatedInformation or not request.textDocument->
    publishDiagnostics->tagSupport.has_value() or request.textDocument->publishDiagnostics->
    tagSupport->valueSet.size() not_eq 1uz or request.textDocument->publishDiagnostics->tagSupport
    ->valueSet[0uz] not_eq Eura::DiagnosticTag::Deprecated or not request.textDocument->
    publishDiagnostics->versionSupport.has_value() or not *request.textDocument->publishDiagnostics
    ->versionSupport or not request.textDocument->publishDiagnostics->codeDescriptionSupport.
    has_value() or not *request.textDocument->publishDiagnostics->codeDescriptionSupport or not
    request.textDocument->publishDiagnostics->dataSupport.has_value() or not *request.textDocument
    ->publishDiagnostics->dataSupport or not request.textDocument->foldingRange.has_value() or not
    request.textDocument->foldingRange->dynamicRegistration.has_value() or not *request.
    textDocument->foldingRange->dynamicRegistration or not request.textDocument->foldingRange->
    rangeLimit.has_value() or *request.textDocument->foldingRange->rangeLimit not_eq 67u or not
    request.textDocument->foldingRange->lineFoldingOnly.has_value() or not *request.textDocument->
    foldingRange->lineFoldingOnly or not request.textDocument->foldingRange->foldingRangeKind.
    has_value() or not request.textDocument->foldingRange->foldingRangeKind->valueSet.has_value()
    or request.textDocument->foldingRange->foldingRangeKind->valueSet->size() not_eq 1uz or (*
    request.textDocument->foldingRange->foldingRangeKind->valueSet)[0uz] not_eq Eura::Comment or
    not request.textDocument->foldingRange->foldingRange.has_value() or not request.textDocument->
    foldingRange->foldingRange->collapsedText.has_value() or not *request.textDocument->
    foldingRange->foldingRange->collapsedText or not request.textDocument->selectionRange.has_value
    () or not request.textDocument->selectionRange->dynamicRegistration.has_value() or not *request
    .textDocument->selectionRange->dynamicRegistration or not request.textDocument->
    linkedEditingRange.has_value() or not request.textDocument->linkedEditingRange->
    dynamicRegistration.has_value() or not *request.textDocument->linkedEditingRange->
    dynamicRegistration or not request.textDocument->callHierarchy.has_value() or not request.
    textDocument->callHierarchy->dynamicRegistration.has_value() or not *request.textDocument->
    callHierarchy->dynamicRegistration or not request.textDocument->semanticTokens.has_value() or
    not request.textDocument->semanticTokens->dynamicRegistration.has_value() or not *request.
    textDocument->semanticTokens->dynamicRegistration or not request.textDocument->semanticTokens->
    requests.range.has_value() or not std::holds_alternative<Eura::Empty>(*request.textDocument->
    semanticTokens->requests.range) or not request.textDocument->semanticTokens->requests.full.
    has_value() or not std::holds_alternative<Eura::ClientSemanticTokensRequestFullDelta>(*request.
    textDocument->semanticTokens->requests.full))
        return false;
    const Eura::ClientSemanticTokensRequestFullDelta& delta = std::get<Eura::
    ClientSemanticTokensRequestFullDelta>(*request.textDocument->semanticTokens->requests.full);
    if(not delta.delta.has_value() or not *delta.delta or request.textDocument->semanticTokens->
    tokenTypes.size() not_eq 1uz or request.textDocument->semanticTokens->tokenTypes[0uz] not_eq
    "meow" or request.textDocument->semanticTokens->tokenModifiers.size() not_eq 1uz or request.
    textDocument->semanticTokens->tokenModifiers[0uz] not_eq "nya" or request.textDocument->
    semanticTokens->formats.size() not_eq 1uz or request.textDocument->semanticTokens->formats[0uz]
    not_eq Eura::Relative or not request.textDocument->semanticTokens->overlappingTokenSupport.
    has_value() or not *request.textDocument->semanticTokens->overlappingTokenSupport or not
    request.textDocument->semanticTokens->multilineTokenSupport.has_value() or not *request.
    textDocument->semanticTokens->multilineTokenSupport or not request.textDocument->semanticTokens
    ->serverCancelSupport.has_value() or not *request.textDocument->semanticTokens->
    serverCancelSupport or not request.textDocument->semanticTokens->augmentsSyntaxTokens.has_value
    () or not *request.textDocument->semanticTokens->augmentsSyntaxTokens or not request.
    textDocument->moniker.has_value() or not request.textDocument->moniker->dynamicRegistration.
    has_value() or not *request.textDocument->moniker->dynamicRegistration or not request.
    textDocument->typeHierarchy.has_value() or not request.textDocument->typeHierarchy->
    dynamicRegistration.has_value() or not *request.textDocument->typeHierarchy->
    dynamicRegistration or not request.textDocument->inlineValue.has_value() or not request.
    textDocument->inlineValue->dynamicRegistration.has_value() or not *request.textDocument->
    inlineValue->dynamicRegistration or not request.textDocument->inlayHint.has_value() or not
    request.textDocument->inlayHint->dynamicRegistration.has_value() or not *request.textDocument->
    inlayHint->dynamicRegistration or not request.textDocument->inlayHint->resolveSupport.has_value
    () or request.textDocument->inlayHint->resolveSupport->properties.size() not_eq 1uz or request.
    textDocument->inlayHint->resolveSupport->properties[0uz] not_eq "meow" or not request.
    textDocument->diagnostic.has_value() or not request.textDocument->diagnostic->
    dynamicRegistration.has_value() or not *request.textDocument->diagnostic->dynamicRegistration
    or not request.textDocument->diagnostic->relatedDocumentSupport.has_value() or not *request.
    textDocument->diagnostic->relatedDocumentSupport or not request.textDocument->diagnostic->
    relatedInformation.has_value() or not *request.textDocument->diagnostic->relatedInformation or
    not request.textDocument->diagnostic->tagSupport.has_value() or request.textDocument->
    diagnostic->tagSupport->valueSet.size() not_eq 1uz or request.textDocument->diagnostic->
    tagSupport->valueSet[0uz] not_eq Eura::DiagnosticTag::Deprecated or not request.textDocument->
    diagnostic->codeDescriptionSupport.has_value() or not *request.textDocument->diagnostic->
    codeDescriptionSupport or not request.textDocument->diagnostic->markupMessageSupport.has_value(
    ) or not *request.textDocument->diagnostic->markupMessageSupport or not request.textDocument->
    diagnostic->dataSupport.has_value() or not *request.textDocument->diagnostic->dataSupport or
    not request.textDocument->inlineCompletion.has_value() or not request.textDocument->
    inlineCompletion->dynamicRegistration.has_value() or not *request.textDocument->
    inlineCompletion->dynamicRegistration or not request.notebookDocument.has_value() or not
    request.notebookDocument->synchronization.dynamicRegistration.has_value() or not *request.
    notebookDocument->synchronization.dynamicRegistration or not request.notebookDocument->
    synchronization.executionSummarySupport.has_value() or not *request.notebookDocument->
    synchronization.executionSummarySupport or not request.window.has_value() or not request.window
    ->workDoneProgress.has_value() or not *request.window->workDoneProgress or not request.window->
    showMessage.has_value() or not request.window->showMessage->messageActionItem.has_value() or
    not request.window->showMessage->messageActionItem->additionalPropertiesSupport.has_value() or
    not *request.window->showMessage->messageActionItem->additionalPropertiesSupport or not request
    .window->showDocument.has_value() or not request.window->showDocument->support or not request.
    general.has_value() or not request.general->staleRequestSupport.has_value() or not request.
    general->staleRequestSupport->cancel or request.general->staleRequestSupport->
    retryOnContentModified.size() not_eq 1uz or request.general->staleRequestSupport->
    retryOnContentModified[0uz] not_eq "meow" or not request.general->regularExpressions.has_value(
    ) or request.general->regularExpressions->engine not_eq Eura::ES2020 or request.general->
    regularExpressions->version not_eq "6.7" or not request.general->markdown.has_value() or
    request.general->markdown->parser not_eq "lyrix" or not request.general->markdown->version.
    has_value() or *request.general->markdown->version not_eq "67" or not request.general->markdown
    ->allowedTags.has_value() or request.general->markdown->allowedTags->size() not_eq 2uz or (*
    request.general->markdown->allowedTags)[0uz] not_eq "meow" or (*request.general->markdown->
    allowedTags)[1uz] not_eq "nya" or not request.general->positionEncodings.has_value() or request
    .general->positionEncodings->size() not_eq 1uz or (*request.general->positionEncodings)[0uz]
    not_eq Eura::UTF8 or not request.experimental.has_value())
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