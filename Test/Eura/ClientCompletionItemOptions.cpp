// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ClientCompletionItemOptions.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"snippetSupport\":true,\"commitCharactersSupport\":true,\"documentationFormat\":[\"markdown\"],\"deprecatedSupport\":true,\"preselectSupport\":true,\"tagSupport\":{\"valueSet\":[1]},\"insertReplaceSupport\":true,\"resolveSupport\":{\"properties\":[\"meow\"]},\"insertTextModeSupport\":{\"valueSet\":[2]},\"labelDetailsSupport\":true}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::ClientCompletionItemOptions request;
    Eura::from_json(root, request);
    if(not request.snippetSupport.has_value() or not *request.snippetSupport or not request.
    commitCharactersSupport.has_value() or not *request.commitCharactersSupport or not request.
    documentationFormat.has_value() or request.documentationFormat->size() not_eq 1uz or (*request.
    documentationFormat)[0uz] not_eq Eura::Markdown or not request.deprecatedSupport.has_value() or
    not *request.deprecatedSupport or not request.preselectSupport.has_value() or not *request.
    preselectSupport or not request.tagSupport.has_value() or request.tagSupport->valueSet.size()
    not_eq 1uz or request.tagSupport->valueSet[0uz] not_eq Eura::CompletionItemTag::Deprecated or
    not request.insertReplaceSupport.has_value() or not *request.insertReplaceSupport or not
    request.resolveSupport.has_value() or request.resolveSupport->properties.size() not_eq 1uz or
    request.resolveSupport->properties[0uz] not_eq "meow" or not request.insertTextModeSupport.
    has_value() or request.insertTextModeSupport->valueSet.size() not_eq 1uz or request.
    insertTextModeSupport->valueSet[0uz] not_eq Eura::InsertTextMode::AdjustIndentation or not
    request.labelDetailsSupport.has_value() or not *request.labelDetailsSupport)
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