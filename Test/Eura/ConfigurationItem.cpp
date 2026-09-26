// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ConfigurationItem.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"scopeUri\":\"meow.extension\",\"section\":\"nya\"}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::ConfigurationItem request;
    Eura::from_json(root, request);
    if(not request.scopeUri.has_value() or *request.scopeUri not_eq "meow.extension" or not request
    .section.has_value() or *request.section not_eq "nya")
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