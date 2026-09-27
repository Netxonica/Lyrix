// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/WorkDoneProgressCancelParams.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"token\":-67}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::WorkDoneProgressCancelParams request;
    Eura::from_json(root, request);
    if(not std::holds_alternative<std::int32_t>(request.token) or std::get<std::int32_t>(request.
    token) not_eq -67)
        return false;
    nlohmann::json response;
    Eura::to_json(response, request);
    return response == root;
}

int main()
{
    return not lyrix_test();
}

#endif