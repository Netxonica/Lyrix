// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/WorkDoneProgressParams.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"workDoneToken\":\"meow\"}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::WorkDoneProgressParams request;
    Eura::from_json(root, request);
    if(not request.workDoneToken.has_value() or not std::holds_alternative<std::string>(*request.
    workDoneToken) or std::get<std::string>(*request.workDoneToken) not_eq "meow")
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