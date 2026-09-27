// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/FileEvent.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"uri\":\"meow.extension\",\"type\":2}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::FileEvent request;
    Eura::from_json(root, request);
    if(request.uri not_eq "meow.extension" or request.type not_eq Eura::FileChangeType::Changed)
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