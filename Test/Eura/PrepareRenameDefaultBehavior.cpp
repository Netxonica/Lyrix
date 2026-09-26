// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/PrepareRenameDefaultBehavior.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"defaultBehavior\":true}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::PrepareRenameDefaultBehavior request;
    Eura::from_json(root, request);
    if(not request.defaultBehavior)
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