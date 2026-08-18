// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/RequestMessage.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"jsonrpc\":\"2.0\",\"id\":\"nya\"}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::RequestMessage request;
    Eura::from_json(root, request);
    if(request.jsonrpc not_eq "2.0" or not std::holds_alternative<std::string>(request.id) or std::
    get<std::string>(request.id) not_eq "nya")
        return false;
    nlohmann::json response;
    Eura::to_json(response, request);
    return root.dump() == response.dump();
}

int main()
{
    return not lyrix_test();
}

#endif