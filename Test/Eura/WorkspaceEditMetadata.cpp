// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/WorkspaceEditMetadata.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"isRefactoring\":true}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::WorkspaceEditMetadata request;
    Eura::from_json(root, request);
    if(not request.isRefactoring.has_value() or not *request.isRefactoring)
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