// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/SignatureHelpClientCapabilities.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"dynamicRegistration\":true,\"signatureInformation\":{\"documentationFormat\":[\"markdown\"],\"parameterInformation\":{\"labelOffsetSupport\":true},\"activeParameterSupport\":true,\"noActiveParameterSupport\":true},\"contextSupport\":true}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::SignatureHelpClientCapabilities request;
    Eura::from_json(root, request);
    if(not request.dynamicRegistration.has_value() or not *request.dynamicRegistration or not
    request.signatureInformation.has_value() or not request.signatureInformation->
    documentationFormat.has_value() or request.signatureInformation->documentationFormat->size()
    not_eq 1uz or (*request.signatureInformation->documentationFormat)[0uz] not_eq Eura::Markdown
    or not request.signatureInformation->parameterInformation.has_value() or not request.
    signatureInformation->parameterInformation->labelOffsetSupport.has_value() or not *request.
    signatureInformation->parameterInformation->labelOffsetSupport or not request.
    signatureInformation->activeParameterSupport.has_value() or not *request.signatureInformation->
    activeParameterSupport or not request.signatureInformation->noActiveParameterSupport.has_value(
    ) or not *request.signatureInformation->noActiveParameterSupport or not request.contextSupport.
    has_value() or not *request.contextSupport)
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