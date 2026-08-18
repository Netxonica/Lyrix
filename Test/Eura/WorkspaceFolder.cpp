// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/WorkspaceFolder.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"uri\":\"meow.extension\",\"name\":\"meow nya\"}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::WorkspaceFolder request;
    Eura::from_json(root, request);
    if(request.uri not_eq "meow.extension" or request.name not_eq "meow nya")
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