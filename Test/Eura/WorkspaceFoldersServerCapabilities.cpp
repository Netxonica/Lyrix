// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/WorkspaceFoldersServerCapabilities.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"supported\":true,\"changeNotifications\":\"meow\"}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::WorkspaceFoldersServerCapabilities request;
    Eura::from_json(root, request);
    if(not request.supported.has_value() or not *request.supported or not request.
    changeNotifications.has_value() or not std::holds_alternative<std::string>(*request.
    changeNotifications) or std::get<std::string>(*request.changeNotifications) not_eq "meow")
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