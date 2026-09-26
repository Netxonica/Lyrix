// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/WorkspaceFoldersChangeEvent.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"added\":[{\"uri\":\"meow.extension\",\"name\":\"meow nya\"}],\"removed\":[{\"uri\":\"meow.extension\",\"name\":\"meow nya\"}]}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::WorkspaceFoldersChangeEvent request;
    Eura::from_json(root, request);
    if(request.added.size() not_eq 1uz or request.added[0uz].uri not_eq "meow.extension" or request
    .added[0uz].name not_eq "meow nya" or request.removed.size() not_eq 1uz or request.removed[0uz]
    .uri not_eq "meow.extension" or request.removed[0uz].name not_eq "meow nya")
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