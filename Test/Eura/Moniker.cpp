// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Moniker.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"scheme\":\"meow\",\"identifier\":\"nya\",\"unique\":\"document\",\"kind\":\"local\"}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::Moniker request;
    Eura::from_json(root, request);
    if(request.scheme not_eq "meow" or request.identifier not_eq "nya" or request.unique not_eq
    Eura::Document or not request.kind.has_value() or *request.kind not_eq Eura::Local)
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