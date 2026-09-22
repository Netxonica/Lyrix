// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/SemanticTokens.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"resultId\":\"meow\",\"data\":[67]}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::SemanticTokens request;
    Eura::from_json(root, request);
    if(not request.resultId.has_value() or *request.resultId not_eq "meow" or request.data.size()
    not_eq 1uz or request.data[0uz] not_eq 67u)
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