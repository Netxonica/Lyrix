// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/WorkspaceSymbolClientCapabilities.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"dynamicRegistration\":true,\"symbolKind\":{\"valueSet\":[1]},\"tagSupport\":{\"valueSet\":[1]},\"resolveSupport\":{\"properties\":[\"meow\"]}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::WorkspaceSymbolClientCapabilities request;
    Eura::from_json(root, request);
    if(not request.dynamicRegistration.has_value() or not *request.dynamicRegistration or not
    request.symbolKind.has_value() or not request.symbolKind->valueSet.has_value() or request.
    symbolKind->valueSet->size() not_eq 1uz or (*request.symbolKind->valueSet)[0u] not_eq Eura::
    SymbolKind::File or not request.tagSupport.has_value() or request.tagSupport->valueSet.size()
    not_eq 1uz or request.tagSupport->valueSet[0uz] not_eq Eura::SymbolTag::Deprecated or not
    request.resolveSupport.has_value() or request.resolveSupport->properties.size() not_eq 1uz or
    request.resolveSupport->properties[0uz] not_eq "meow")
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