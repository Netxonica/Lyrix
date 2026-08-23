// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/SemanticTokensClientCapabilities.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"dynamicRegistration\":true,\"requests\":{\"range\":{},\"full\":{\"delta\":true}},\"tokenTypes\":[\"meow\"],\"tokenModifiers\":[\"nya\"],\"formats\":[\"relative\"],\"overlappingTokenSupport\":true,\"multilineTokenSupport\":true,\"serverCancelSupport\":true,\"augmentsSyntaxTokens\":true}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::SemanticTokensClientCapabilities request;
    Eura::from_json(root, request);
    if(not request.dynamicRegistration.has_value() or not *request.dynamicRegistration or not
    request.requests.range.has_value() or not std::holds_alternative<Eura::Empty>(*request.requests
    .range) or not request.requests.full.has_value() or not std::holds_alternative<Eura::
    ClientSemanticTokensRequestFullDelta>(*request.requests.full))
        return false;
    const Eura::ClientSemanticTokensRequestFullDelta& delta = std::get<Eura::
    ClientSemanticTokensRequestFullDelta>(*request.requests.full);
    if(not delta.delta.has_value() or not *delta.delta or request.tokenTypes.size() not_eq 1uz or
    request.tokenTypes[0uz] not_eq "meow" or request.tokenModifiers.size() not_eq 1uz or request.
    tokenModifiers[0uz] not_eq "nya" or request.formats.size() not_eq 1uz or request.formats[0uz]
    not_eq Eura::Relative or not request.overlappingTokenSupport.has_value() or not *request.
    overlappingTokenSupport or not request.multilineTokenSupport.has_value() or not *request.
    multilineTokenSupport or not request.serverCancelSupport.has_value() or not *request.
    serverCancelSupport or not request.augmentsSyntaxTokens.has_value() or not *request.
    augmentsSyntaxTokens)
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