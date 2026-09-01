// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/TextDocumentClientCapabilities.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"synchronization\":{\"dynamicRegistration\":true,\"willSave\":true,\"willSaveWaitUntil\":true,\"didSave\":true},\"filters\":{\"relativePatternSupport\":true},\"completion\":{\"dynamicRegistration\":true,\"completionItem\":{\"snippetSupport\":true,\"commitCharactersSupport\":true,\"documentationFormat\":[\"markdown\"],\"deprecatedSupport\":true,\"preselectSupport\":true,\"tagSupport\":{\"valueSet\":[1]},\"insertReplaceSupport\":true,\"resolveSupport\":{\"properties\":[\"meow\"]},\"insertTextModeSupport\":{\"valueSet\":[2]},\"labelDetailsSupport\":true},\"completionItemKind\":{\"valueSet\":[3]},\"contextSupport\":true,\"insertTextMode\":2,\"completionList\":{\"itemDefaults\":[\"meow\"],\"applyKindSupport\":true}},\"hover\":{\"dynamicRegistration\":true,\"contentFormat\":[\"markdown\"]},\"signatureHelp\":{\"dynamicRegistration\":true,\"signatureInformation\":{\"documentationFormat\":[\"markdown\"],\"parameterInformation\":{\"labelOffsetSupport\":true},\"activeParameterSupport\":true,\"noActiveParameterSupport\":true},\"contextSupport\":true},\"declaration\":{\"dynamicRegistration\":true,\"linkSupport\":true},\"definition\":{\"dynamicRegistration\":true,\"linkSupport\":true},\"typeDefinition\":{\"dynamicRegistration\":true,\"linkSupport\":true},\"implementation\":{\"dynamicRegistration\":true,\"linkSupport\":true},\"references\":{\"dynamicRegistration\":true},\"documentHighlight\":{\"dynamicRegistration\":true},\"documentSymbol\":{\"dynamicRegistration\":true,\"symbolKind\":{\"valueSet\":[1]},\"hierarchicalDocumentSymbolSupport\":true,\"tagSupport\":{\"valueSet\":[1]},\"labelSupport\":true},\"codeAction\":{\"dynamicRegistration\":true,\"codeActionLiteralSupport\":{\"codeActionKind\":{\"valueSet\":[\"source\"]}},\"isPreferredSupport\":true,\"disabledSupport\":true,\"dataSupport\":true,\"resolveSupport\":{\"properties\":[\"meow\"]},\"honorsChangeAnnotations\":true,\"documentationSupport\":true,\"tagSupport\":{\"valueSet\":[1]}},\"codeLens\":{\"dynamicRegistration\":true,\"resolveSupport\":{\"properties\":[\"meow\"]}},\"documentLink\":{\"dynamicRegistration\":true,\"tooltipSupport\":true},\"colorProvider\":{\"dynamicRegistration\":true},\"formatting\":{\"dynamicRegistration\":true},\"rangeFormatting\":{\"dynamicRegistration\":true,\"rangesSupport\":true},\"onTypeFormatting\":{\"dynamicRegistration\":true},\"rename\":{\"dynamicRegistration\":true,\"prepareSupport\":true,\"prepareSupportDefaultBehavior\":1,\"honorsChangeAnnotations\":true},\"publishDiagnostics\":{\"relatedInformation\":true,\"tagSupport\":{\"valueSet\":[2]},\"versionSupport\":true,\"codeDescriptionSupport\":true,\"dataSupport\":true},\"foldingRange\":{\"dynamicRegistration\":true,\"rangeLimit\":67,\"lineFoldingOnly\":true,\"foldingRangeKind\":{\"valueSet\":[\"comment\"]},\"foldingRange\":{\"collapsedText\":true}},\"selectionRange\":{\"dynamicRegistration\":true},\"linkedEditingRange\":{\"dynamicRegistration\":true},\"callHierarchy\":{\"dynamicRegistration\":true},\"semanticTokens\":{\"dynamicRegistration\":true,\"requests\":{\"range\":{},\"full\":{\"delta\":true}},\"tokenTypes\":[\"meow\"],\"tokenModifiers\":[\"nya\"],\"formats\":[\"relative\"],\"overlappingTokenSupport\":true,\"multilineTokenSupport\":true,\"serverCancelSupport\":true,\"augmentsSyntaxTokens\":true},\"moniker\":{\"dynamicRegistration\":true},\"typeHierarchy\":{\"dynamicRegistration\":true},\"inlineValue\":{\"dynamicRegistration\":true},\"inlayHint\":{\"dynamicRegistration\":true,\"resolveSupport\":{\"properties\":[\"meow\"]}},\"diagnostic\":{\"dynamicRegistration\":true,\"relatedDocumentSupport\":true,\"relatedInformation\":true,\"tagSupport\":{\"valueSet\":[2]},\"codeDescriptionSupport\":true,\"markupMessageSupport\":true,\"dataSupport\":true},\"inlineCompletion\":{\"dynamicRegistration\":true}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::TextDocumentClientCapabilities request;
    Eura::from_json(root, request);
    if(not request.synchronization.has_value() or not request.synchronization->dynamicRegistration.
    has_value() or not *request.synchronization->dynamicRegistration or not request.synchronization
    ->willSave.has_value() or not *request.synchronization->willSave or not request.synchronization
    ->willSaveWaitUntil.has_value() or not *request.synchronization->willSaveWaitUntil or not
    request.synchronization->didSave.has_value() or not *request.synchronization->didSave or not
    request.filters.has_value() or not request.filters->relativePatternSupport.has_value() or not *
    request.filters->relativePatternSupport or not request.completion.has_value() or not request.
    completion->dynamicRegistration.has_value() or not *request.completion->dynamicRegistration or
    not request.completion->completionItem.has_value() or not request.completion->completionItem->
    snippetSupport.has_value() or not *request.completion->completionItem->snippetSupport or not
    request.completion->completionItem->commitCharactersSupport.has_value() or not *request.
    completion->completionItem->commitCharactersSupport or not request.completion->completionItem->
    documentationFormat.has_value() or request.completion->completionItem->documentationFormat->
    size() not_eq 1uz or (*request.completion->completionItem->documentationFormat)[0uz] not_eq
    Eura::Markdown or not request.completion->completionItem->deprecatedSupport.has_value() or not
    *request.completion->completionItem->deprecatedSupport or not request.completion->
    completionItem->preselectSupport.has_value() or not *request.completion->completionItem->
    preselectSupport or not request.completion->completionItem->tagSupport.has_value() or request.
    completion->completionItem->tagSupport->valueSet.size() not_eq 1uz or request.completion->
    completionItem->tagSupport->valueSet[0uz] not_eq Eura::CompletionItemTag::Deprecated or not
    request.completion->completionItem->insertReplaceSupport.has_value() or not *request.completion
    ->completionItem->insertReplaceSupport or not request.completion->completionItem->
    resolveSupport.has_value() or request.completion->completionItem->resolveSupport->properties.
    size() not_eq 1uz or request.completion->completionItem->resolveSupport->properties[0uz] not_eq
    "meow" or not request.completion->completionItem->insertTextModeSupport.has_value() or request.
    completion->completionItem->insertTextModeSupport->valueSet.size() not_eq 1uz or request.
    completion->completionItem->insertTextModeSupport->valueSet[0uz] not_eq Eura::InsertTextMode::
    AdjustIndentation or not request.completion->completionItem->labelDetailsSupport.has_value() or
    not *request.completion->completionItem->labelDetailsSupport or not request.completion->
    completionItemKind.has_value() or not request.completion->completionItemKind->valueSet.
    has_value() or request.completion->completionItemKind->valueSet->size() not_eq 1uz or (*request
    .completion->completionItemKind->valueSet)[0uz] not_eq Eura::CompletionItemKind::Function or
    not request.completion->contextSupport.has_value() or not *request.completion->contextSupport
    or not request.completion->insertTextMode.has_value() or *request.completion->insertTextMode
    not_eq Eura::InsertTextMode::AdjustIndentation or not request.completion->completionList.
    has_value() or not request.completion->completionList->itemDefaults.has_value() or request.
    completion->completionList->itemDefaults->size() not_eq 1uz or (*request.completion->
    completionList->itemDefaults)[0uz] not_eq "meow" or not request.completion->completionList->
    applyKindSupport.has_value() or not *request.completion->completionList->applyKindSupport or
    not request.hover.has_value() or not request.hover->dynamicRegistration.has_value() or not *
    request.hover->dynamicRegistration or not request.hover->contentFormat.has_value() or request.
    hover->contentFormat->size() not_eq 1uz or (*request.hover->contentFormat)[0uz] not_eq Eura::
    Markdown or not request.signatureHelp.has_value() or not request.signatureHelp->
    dynamicRegistration.has_value() or not *request.signatureHelp->dynamicRegistration or not
    request.signatureHelp->signatureInformation.has_value() or not request.signatureHelp->
    signatureInformation->documentationFormat.has_value() or request.signatureHelp->
    signatureInformation->documentationFormat->size() not_eq 1uz or (*request.signatureHelp->
    signatureInformation->documentationFormat)[0uz] not_eq Eura::Markdown or not request.
    signatureHelp->signatureInformation->parameterInformation.has_value() or not request.
    signatureHelp->signatureInformation->parameterInformation->labelOffsetSupport.has_value() or
    not *request.signatureHelp->signatureInformation->parameterInformation->labelOffsetSupport or
    not request.signatureHelp->signatureInformation->activeParameterSupport.has_value() or not *
    request.signatureHelp->signatureInformation->activeParameterSupport or not request.
    signatureHelp->signatureInformation->noActiveParameterSupport.has_value() or not *request.
    signatureHelp->signatureInformation->noActiveParameterSupport or not request.signatureHelp->
    contextSupport.has_value() or not *request.signatureHelp->contextSupport or not request.
    declaration.has_value() or not request.declaration->dynamicRegistration.has_value() or not *
    request.declaration->dynamicRegistration or not request.declaration->linkSupport.has_value() or
    not *request.declaration->linkSupport or not request.definition.has_value() or not request.
    definition->dynamicRegistration.has_value() or not *request.definition->dynamicRegistration or
    not request.definition->linkSupport.has_value() or not *request.definition->linkSupport or not
    request.typeDefinition.has_value() or not request.typeDefinition->dynamicRegistration.has_value
    () or not *request.typeDefinition->dynamicRegistration or not request.typeDefinition->
    linkSupport.has_value() or not *request.typeDefinition->linkSupport or not request.
    implementation.has_value() or not request.implementation->dynamicRegistration.has_value() or
    not *request.implementation->dynamicRegistration or not request.implementation->linkSupport.
    has_value() or not *request.implementation->linkSupport or not request.references.has_value()
    or not request.references->dynamicRegistration.has_value() or not *request.references->
    dynamicRegistration or not request.documentHighlight.has_value() or not request.
    documentHighlight->dynamicRegistration.has_value() or not *request.documentHighlight->
    dynamicRegistration or not request.documentSymbol.has_value() or not request.documentSymbol->
    dynamicRegistration.has_value() or not *request.documentSymbol->dynamicRegistration or not
    request.documentSymbol->symbolKind.has_value() or not request.documentSymbol->symbolKind->
    valueSet.has_value() or request.documentSymbol->symbolKind->valueSet->size() not_eq 1uz or (*
    request.documentSymbol->symbolKind->valueSet)[0u] not_eq Eura::SymbolKind::File or not request.
    documentSymbol->hierarchicalDocumentSymbolSupport.has_value() or not *request.documentSymbol->
    hierarchicalDocumentSymbolSupport or not request.documentSymbol->tagSupport.has_value() or
    request.documentSymbol->tagSupport->valueSet.size() not_eq 1uz or request.documentSymbol->
    tagSupport->valueSet[0uz] not_eq Eura::SymbolTag::Deprecated or not request.documentSymbol->
    labelSupport.has_value() or not *request.documentSymbol->labelSupport or not request.codeAction
    .has_value() or not request.codeAction->dynamicRegistration.has_value() or not *request.
    codeAction->dynamicRegistration or not request.codeAction->codeActionLiteralSupport.has_value()
    or request.codeAction->codeActionLiteralSupport->codeActionKind.valueSet.size() not_eq 1uz or
    request.codeAction->codeActionLiteralSupport->codeActionKind.valueSet[0uz] not_eq Eura::Source
    or not request.codeAction->isPreferredSupport.has_value() or not *request.codeAction->
    isPreferredSupport or not request.codeAction->disabledSupport.has_value() or not *request.
    codeAction->disabledSupport or not request.codeAction->dataSupport.has_value() or not *request.
    codeAction->dataSupport or not request.codeAction->resolveSupport.has_value() or request.
    codeAction->resolveSupport->properties.size() not_eq 1uz or request.codeAction->resolveSupport
    ->properties[0uz] not_eq "meow" or not request.codeAction->honorsChangeAnnotations.has_value()
    or not *request.codeAction->honorsChangeAnnotations or not request.codeAction->
    documentationSupport.has_value() or not *request.codeAction->documentationSupport or not
    request.codeAction->tagSupport.has_value() or request.codeAction->tagSupport->valueSet.size()
    not_eq 1uz or request.codeAction->tagSupport->valueSet[0uz] not_eq Eura::CodeActionTag::
    LLMGenerated or not request.codeLens.has_value() or not request.codeLens->dynamicRegistration.
    has_value() or not *request.codeLens->dynamicRegistration or not request.codeLens->
    resolveSupport.has_value() or request.codeLens->resolveSupport->properties.size() not_eq 1uz or
    request.codeLens->resolveSupport->properties[0uz] not_eq "meow" or not request.documentLink.
    has_value() or not request.documentLink->dynamicRegistration.has_value() or not *request.
    documentLink->dynamicRegistration or not request.documentLink->tooltipSupport.has_value() or
    not *request.documentLink->tooltipSupport or not request.colorProvider.has_value() or not
    request.colorProvider->dynamicRegistration.has_value() or not *request.colorProvider->
    dynamicRegistration or not request.formatting.has_value() or not request.formatting->
    dynamicRegistration.has_value() or not *request.formatting->dynamicRegistration or not request.
    rangeFormatting.has_value() or not request.rangeFormatting->dynamicRegistration.has_value() or
    not *request.rangeFormatting->dynamicRegistration or not request.rangeFormatting->rangesSupport
    .has_value() or not *request.rangeFormatting->rangesSupport or not request.onTypeFormatting.
    has_value() or not request.onTypeFormatting->dynamicRegistration.has_value() or not *request.
    onTypeFormatting->dynamicRegistration or not request.rename.has_value() or not request.rename->
    dynamicRegistration.has_value() or not *request.rename->dynamicRegistration or not request.
    rename->prepareSupport.has_value() or not *request.rename->prepareSupport or not request.rename
    ->prepareSupportDefaultBehavior.has_value() or *request.rename->prepareSupportDefaultBehavior
    not_eq Eura::PrepareSupportDefaultBehavior::Identifier or not request.rename->
    honorsChangeAnnotations.has_value() or not *request.rename->honorsChangeAnnotations or not
    request.publishDiagnostics.has_value() or not request.publishDiagnostics->relatedInformation.
    has_value() or not *request.publishDiagnostics->relatedInformation or not request.
    publishDiagnostics->tagSupport.has_value() or request.publishDiagnostics->tagSupport->valueSet.
    size() not_eq 1uz or request.publishDiagnostics->tagSupport->valueSet[0uz] not_eq Eura::
    DiagnosticTag::Deprecated or not request.publishDiagnostics->versionSupport.has_value() or not
    *request.publishDiagnostics->versionSupport or not request.publishDiagnostics->
    codeDescriptionSupport.has_value() or not *request.publishDiagnostics->codeDescriptionSupport
    or not request.publishDiagnostics->dataSupport.has_value() or not *request.publishDiagnostics->
    dataSupport or not request.foldingRange.has_value() or not request.foldingRange->
    dynamicRegistration.has_value() or not *request.foldingRange->dynamicRegistration or not
    request.foldingRange->rangeLimit.has_value() or *request.foldingRange->rangeLimit not_eq 67u or
    not request.foldingRange->lineFoldingOnly.has_value() or not *request.foldingRange->
    lineFoldingOnly or not request.foldingRange->foldingRangeKind.has_value() or not request.
    foldingRange->foldingRangeKind->valueSet.has_value() or request.foldingRange->foldingRangeKind
    ->valueSet->size() not_eq 1uz or (*request.foldingRange->foldingRangeKind->valueSet)[0uz]
    not_eq Eura::Comment or not request.foldingRange->foldingRange.has_value() or not request.
    foldingRange->foldingRange->collapsedText.has_value() or not *request.foldingRange->
    foldingRange->collapsedText or not request.selectionRange.has_value() or not request.
    selectionRange->dynamicRegistration.has_value() or not *request.selectionRange->
    dynamicRegistration or not request.linkedEditingRange.has_value() or not request.
    linkedEditingRange->dynamicRegistration.has_value() or not *request.linkedEditingRange->
    dynamicRegistration or not request.callHierarchy.has_value() or not request.callHierarchy->
    dynamicRegistration.has_value() or not *request.callHierarchy->dynamicRegistration or not
    request.semanticTokens.has_value() or not request.semanticTokens->dynamicRegistration.has_value
    () or not *request.semanticTokens->dynamicRegistration or not request.semanticTokens->requests.
    range.has_value() or not std::holds_alternative<Eura::Empty>(*request.semanticTokens->requests.
    range) or not request.semanticTokens->requests.full.has_value() or not std::holds_alternative<
    Eura::ClientSemanticTokensRequestFullDelta>(*request.semanticTokens->requests.full))
        return false;
    const Eura::ClientSemanticTokensRequestFullDelta& delta = std::get<Eura::
    ClientSemanticTokensRequestFullDelta>(*request.semanticTokens->requests.full);
    if(not delta.delta.has_value() or not *delta.delta or request.semanticTokens->tokenTypes.size()
    not_eq 1uz or request.semanticTokens->tokenTypes[0uz] not_eq "meow" or request.semanticTokens->
    tokenModifiers.size() not_eq 1uz or request.semanticTokens->tokenModifiers[0uz] not_eq "nya" or
    request.semanticTokens->formats.size() not_eq 1uz or request.semanticTokens->formats[0uz]
    not_eq Eura::Relative or not request.semanticTokens->overlappingTokenSupport.has_value() or not
    *request.semanticTokens->overlappingTokenSupport or not request.semanticTokens->
    multilineTokenSupport.has_value() or not *request.semanticTokens->multilineTokenSupport or not
    request.semanticTokens->serverCancelSupport.has_value() or not *request.semanticTokens->
    serverCancelSupport or not request.semanticTokens->augmentsSyntaxTokens.has_value() or not *
    request.semanticTokens->augmentsSyntaxTokens or not request.moniker.has_value() or not request.
    moniker->dynamicRegistration.has_value() or not *request.moniker->dynamicRegistration or not
    request.typeHierarchy.has_value() or not request.typeHierarchy->dynamicRegistration.has_value()
    or not *request.typeHierarchy->dynamicRegistration or not request.inlineValue.has_value() or
    not request.inlineValue->dynamicRegistration.has_value() or not *request.inlineValue->
    dynamicRegistration or not request.inlayHint.has_value() or not request.inlayHint->
    dynamicRegistration.has_value() or not *request.inlayHint->dynamicRegistration or not request.
    inlayHint->resolveSupport.has_value() or request.inlayHint->resolveSupport->properties.size()
    not_eq 1uz or request.inlayHint->resolveSupport->properties[0uz] not_eq "meow" or not request.
    diagnostic.has_value() or not request.diagnostic->dynamicRegistration.has_value() or not *
    request.diagnostic->dynamicRegistration or not request.diagnostic->relatedDocumentSupport.
    has_value() or not *request.diagnostic->relatedDocumentSupport or not request.diagnostic->
    relatedInformation.has_value() or not *request.diagnostic->relatedInformation or not request.
    diagnostic->tagSupport.has_value() or request.diagnostic->tagSupport->valueSet.size() not_eq
    1uz or request.diagnostic->tagSupport->valueSet[0uz] not_eq Eura::DiagnosticTag::Deprecated or
    not request.diagnostic->codeDescriptionSupport.has_value() or not *request.diagnostic->
    codeDescriptionSupport or not request.diagnostic->markupMessageSupport.has_value() or not *
    request.diagnostic->markupMessageSupport or not request.diagnostic->dataSupport.has_value() or
    not *request.diagnostic->dataSupport or not request.inlineCompletion.has_value() or not request
    .inlineCompletion->dynamicRegistration.has_value() or not *request.inlineCompletion->
    dynamicRegistration)
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