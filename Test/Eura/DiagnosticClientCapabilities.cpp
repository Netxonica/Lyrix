// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DiagnosticClientCapabilities.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"dynamicRegistration\":true,\"relatedDocumentSupport\":true,\"relatedInformation\":true,\"tagSupport\":{\"valueSet\":[2]},\"codeDescriptionSupport\":true,\"markupMessageSupport\":true,\"dataSupport\":true}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::DiagnosticClientCapabilities request;
    Eura::from_json(root, request);
    if(not request.dynamicRegistration.has_value() or not *request.dynamicRegistration or not
    request.relatedDocumentSupport.has_value() or not *request.relatedDocumentSupport or not
    request.relatedInformation.has_value() or not *request.relatedInformation or not request.
    tagSupport.has_value() or request.tagSupport->valueSet.size() not_eq 1uz or request.tagSupport
    ->valueSet[0uz] not_eq Eura::DiagnosticTag::Deprecated or not request.codeDescriptionSupport.
    has_value() or not *request.codeDescriptionSupport or not request.markupMessageSupport.
    has_value() or not *request.markupMessageSupport or not request.dataSupport.has_value() or not
    *request.dataSupport)
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