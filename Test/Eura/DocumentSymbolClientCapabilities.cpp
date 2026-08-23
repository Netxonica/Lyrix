// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DocumentSymbolClientCapabilities.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"dynamicRegistration\":true,\"symbolKind\":{\"valueSet\":[1]},\"hierarchicalDocumentSymbolSupport\":true,\"tagSupport\":{\"valueSet\":[1]},\"labelSupport\":true}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::DocumentSymbolClientCapabilities request;
    Eura::from_json(root, request);
    if(not request.dynamicRegistration.has_value() or not *request.dynamicRegistration or not
    request.symbolKind.has_value() or not request.symbolKind->valueSet.has_value() or request.
    symbolKind->valueSet->size() not_eq 1uz or (*request.symbolKind->valueSet)[0u] not_eq Eura::
    SymbolKind::File or not request.hierarchicalDocumentSymbolSupport.has_value() or not *request.
    hierarchicalDocumentSymbolSupport or not request.tagSupport.has_value() or request.tagSupport->
    valueSet.size() not_eq 1uz or request.tagSupport->valueSet[0uz] not_eq Eura::SymbolTag::
    Deprecated or not request.labelSupport.has_value() or not *request.labelSupport)
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