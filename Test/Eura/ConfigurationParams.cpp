// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ConfigurationParams.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"items\":[{\"scopeUri\":\"meow.extension\",\"section\":\"nya\"}]}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::ConfigurationParams request;
    Eura::from_json(root, request);
    if(request.items.size() not_eq 1uz or not request.items[0uz].scopeUri.has_value() or *request.
    items[0uz].scopeUri not_eq "meow.extension" or not request.items[0uz].section.has_value() or *
    request.items[0uz].section not_eq "nya")
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