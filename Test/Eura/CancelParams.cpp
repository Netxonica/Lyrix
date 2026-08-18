// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CancelParams.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"id\":\"meow\"}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::CancelParams request;
    Eura::from_json(root, request);
    if(not std::holds_alternative<std::string>(request.id) or std::get<std::string>(request.id)
    not_eq "meow")
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