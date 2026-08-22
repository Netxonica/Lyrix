// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CompletionClientCapabilities.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"dynamicRegistration\":true,\"completionItem\":{\"snippetSupport\":true,\"commitCharactersSupport\":true,\"documentationFormat\":[\"markdown\"],\"deprecatedSupport\":true,\"preselectSupport\":true,\"tagSupport\":{\"valueSet\":[1]},\"insertReplaceSupport\":true,\"resolveSupport\":{\"properties\":[\"meow\"]},\"insertTextModeSupport\":{\"valueSet\":[2]},\"labelDetailsSupport\":true},\"completionItemKind\":{\"valueSet\":[3]},\"contextSupport\":true,\"insertTextMode\":2,\"completionList\":{\"itemDefaults\":[\"meow\"],\"applyKindSupport\":true}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::CompletionClientCapabilities request;
    Eura::from_json(root, request);
    if(not request.dynamicRegistration.has_value() or not *request.dynamicRegistration or not
    request.completionItem.has_value() or not request.completionItem->snippetSupport.has_value() or
    not *request.completionItem->snippetSupport or not request.completionItem->
    commitCharactersSupport.has_value() or not *request.completionItem->commitCharactersSupport or
    not request.completionItem->documentationFormat.has_value() or request.completionItem->
    documentationFormat->size() not_eq 1uz or (*request.completionItem->documentationFormat)[0uz]
    not_eq Eura::Markdown or not request.completionItem->deprecatedSupport.has_value() or not *
    request.completionItem->deprecatedSupport or not request.completionItem->preselectSupport.
    has_value() or not *request.completionItem->preselectSupport or not request.completionItem->
    tagSupport.has_value() or request.completionItem->tagSupport->valueSet.size() not_eq 1uz or
    request.completionItem->tagSupport->valueSet[0uz] not_eq Eura::CompletionItemTag::Deprecated or
    not request.completionItem->insertReplaceSupport.has_value() or not *request.completionItem->
    insertReplaceSupport or not request.completionItem->resolveSupport.has_value() or request.
    completionItem->resolveSupport->properties.size() not_eq 1uz or request.completionItem->
    resolveSupport->properties[0uz] not_eq "meow" or not request.completionItem->
    insertTextModeSupport.has_value() or request.completionItem->insertTextModeSupport->valueSet.
    size() not_eq 1uz or request.completionItem->insertTextModeSupport->valueSet[0uz] not_eq Eura::
    InsertTextMode::AdjustIndentation or not request.completionItem->labelDetailsSupport.has_value(
    ) or not *request.completionItem->labelDetailsSupport or not request.completionItemKind.
    has_value() or not request.completionItemKind->valueSet.has_value() or request.
    completionItemKind->valueSet->size() not_eq 1uz or (*request.completionItemKind->valueSet)[0uz]
    not_eq Eura::CompletionItemKind::Function or not request.contextSupport.has_value() or not *
    request.contextSupport or not request.insertTextMode.has_value() or *request.insertTextMode
    not_eq Eura::InsertTextMode::AdjustIndentation or not request.completionList.has_value() or not
    request.completionList->itemDefaults.has_value() or request.completionList->itemDefaults->size(
    ) not_eq 1uz or (*request.completionList->itemDefaults)[0uz] not_eq "meow" or not request.
    completionList->applyKindSupport.has_value() or not *request.completionList->applyKindSupport)
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