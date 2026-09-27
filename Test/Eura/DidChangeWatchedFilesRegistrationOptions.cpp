// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DidChangeWatchedFilesRegistrationOptions.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"watchers\":[{\"globPattern\":\"meow\",\"kind\":2}]}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::DidChangeWatchedFilesRegistrationOptions request;
    Eura::from_json(root, request);
    if(request.watchers.size() not_eq 1uz or not std::holds_alternative<Eura::Pattern>(request.
    watchers[0uz].globPattern) or std::get<Eura::Pattern>(request.watchers[0uz].globPattern) not_eq
    "meow" or not request.watchers[0uz].kind.has_value() or *request.watchers[0uz].kind not_eq Eura
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