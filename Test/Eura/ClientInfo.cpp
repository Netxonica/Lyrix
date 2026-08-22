// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ClientInfo.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"name\":\"meow\",\"version\":\"6.7\"}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::ClientInfo request;
    Eura::from_json(root, request);
    if(request.name not_eq "meow" or not request.version.has_value() or *request.version not_eq
    "6.7")
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