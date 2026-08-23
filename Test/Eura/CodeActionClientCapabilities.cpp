// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CodeActionClientCapabilities.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"dynamicRegistration\":true,\"codeActionLiteralSupport\":{\"codeActionKind\":{\"valueSet\":[\"source\"]}},\"isPreferredSupport\":true,\"disabledSupport\":true,\"dataSupport\":true,\"resolveSupport\":{\"properties\":[\"meow\"]},\"honorsChangeAnnotations\":true,\"documentationSupport\":true,\"tagSupport\":{\"valueSet\":[1]}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::CodeActionClientCapabilities request;
    Eura::from_json(root, request);
    if(not request.dynamicRegistration.has_value() or not *request.dynamicRegistration or not
    request.codeActionLiteralSupport.has_value() or request.codeActionLiteralSupport->
    codeActionKind.valueSet.size() not_eq 1uz or request.codeActionLiteralSupport->codeActionKind.
    valueSet[0uz] not_eq Eura::Source or not request.isPreferredSupport.has_value() or not *request
    .isPreferredSupport or not request.disabledSupport.has_value() or not *request.disabledSupport
    or not request.dataSupport.has_value() or not *request.dataSupport or not request.
    resolveSupport.has_value() or request.resolveSupport->properties.size() not_eq 1uz or request.
    resolveSupport->properties[0uz] not_eq "meow" or not request.honorsChangeAnnotations.has_value(
    ) or not *request.honorsChangeAnnotations or not request.documentationSupport.has_value() or
    not *request.documentationSupport or not request.tagSupport.has_value() or request.tagSupport->
    valueSet.size() not_eq 1uz or request.tagSupport->valueSet[0uz] not_eq Eura::CodeActionTag::
    LLMGenerated)
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