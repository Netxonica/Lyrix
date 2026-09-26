// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/FileSystemWatcher.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"globPattern\":\"meow\",\"kind\":2}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::FileSystemWatcher request;
    Eura::from_json(root, request);
    if(not std::holds_alternative<Eura::Pattern>(request.globPattern) or std::get<Eura::Pattern>(
    request.globPattern) not_eq "meow" or not request.kind.has_value() or *request.kind not_eq Eura
    ::WatchKind::Change)
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