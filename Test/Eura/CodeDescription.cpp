// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CodeDescription.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"href\":\"meow.extension\"}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::CodeDescription request;
    Eura::from_json(root, request);
    if(request.href not_eq "meow.extension")
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