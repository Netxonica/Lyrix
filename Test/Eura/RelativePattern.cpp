// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/RelativePattern.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"baseUri\":{\"uri\":\"meow.extension\",\"name\":\"meow nya\"},\"pattern\":\"*.extension\"}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::RelativePattern request;
    Eura::from_json(root, request);
    if(not std::holds_alternative<Eura::WorkspaceFolder>(request.baseUri))
        return false;
    const Eura::WorkspaceFolder& workspace_folder = std::get<Eura::WorkspaceFolder>(request.baseUri
    );
    if(workspace_folder.uri not_eq "meow.extension" or workspace_folder.name not_eq "meow nya" or
    request.pattern not_eq "*.extension")
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