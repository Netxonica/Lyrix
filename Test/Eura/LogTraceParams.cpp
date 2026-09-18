// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/LogTraceParams.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"message\":\"meow\",\"verbose\":\"nya\"}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::LogTraceParams request;
    Eura::from_json(root, request);
    if(request.message not_eq "meow" or not request.verbose.has_value() or *request.verbose not_eq
    "nya")
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