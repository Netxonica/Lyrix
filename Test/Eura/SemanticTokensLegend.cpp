// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/SemanticTokensLegend.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"tokenTypes\":[\"meow\"],\"tokenModifiers\":[\"nya\"]}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::SemanticTokensLegend request;
    Eura::from_json(root, request);
    if(request.tokenTypes.size() not_eq 1uz or request.tokenTypes[0uz] not_eq "meow" or request.
    tokenModifiers.size() not_eq 1uz or request.tokenModifiers[0uz] not_eq "nya")
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