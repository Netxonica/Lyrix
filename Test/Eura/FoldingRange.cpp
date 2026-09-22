// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/FoldingRange.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"startLine\":0,\"startCharacter\":1,\"endLine\":42,\"endCharacter\":67,\"kind\":\"region\",\"collapsedText\":\"nya\"}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::FoldingRange request;
    Eura::from_json(root, request);
    if(request.startLine not_eq 0u or not request.startCharacter.has_value() or *request.
    startCharacter not_eq 1uz or request.endLine not_eq 42u or not request.endCharacter.has_value()
    or *request.endCharacter not_eq 67u or not request.kind.has_value() or *request.kind not_eq
    Eura::Region or not request.collapsedText.has_value() or *request.collapsedText not_eq "nya")
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