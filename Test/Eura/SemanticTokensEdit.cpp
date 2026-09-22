// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/SemanticTokensEdit.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"start\":0,\"deleteCount\":42,\"data\":[67]}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::SemanticTokensEdit request;
    Eura::from_json(root, request);
    if(request.start not_eq 0u or request.deleteCount not_eq 42u or not request.data.has_value() or
    (*request.data)[0uz] not_eq 67u)
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