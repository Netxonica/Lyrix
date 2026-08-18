// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/HoverParams.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"textDocument\":\"meow nya\",\"position\":{\"line\":42,\"character\":67}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::HoverParams request;
    Eura::from_json(root, request);
    if(request.textDocument not_eq "meow nya" or request.position.line not_eq 42u or request.
    position.character not_eq 67u)
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