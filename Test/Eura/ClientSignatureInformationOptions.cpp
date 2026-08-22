// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ClientSignatureInformationOptions.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"documentationFormat\":[\"markdown\"],\"parameterInformation\":{\"labelOffsetSupport\":true},\"activeParameterSupport\":true,\"noActiveParameterSupport\":true}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::ClientSignatureInformationOptions request;
    Eura::from_json(root, request);
    if(not request.documentationFormat.has_value() or request.documentationFormat->size() not_eq
    1uz or (*request.documentationFormat)[0uz] not_eq Eura::Markdown or not request.
    parameterInformation.has_value() or not request.parameterInformation->labelOffsetSupport.
    has_value() or not *request.parameterInformation->labelOffsetSupport or not request.
    activeParameterSupport.has_value() or not *request.activeParameterSupport or not request.
    noActiveParameterSupport.has_value() or not *request.noActiveParameterSupport)
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