// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ExecutionSummary.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"executionOrder\":67,\"success\":true}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::ExecutionSummary request;
    Eura::from_json(root, request);
    if(request.executionOrder not_eq 67u or not request.success.has_value() or not *request.success
    )
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