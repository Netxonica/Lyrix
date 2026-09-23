// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CompletionItemLabelDetails.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"detail\":\"meow\",\"description\":\"nya\"}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::CompletionItemLabelDetails request;
    Eura::from_json(root, request);
    if(not request.detail.has_value() or *request.detail not_eq "meow" or not request.description.
    has_value() or *request.description not_eq "nya")
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