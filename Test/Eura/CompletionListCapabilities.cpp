// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CompletionListCapabilities.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"itemDefaults\":[\"meow\"],\"applyKindSupport\":true}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::CompletionListCapabilities request;
    Eura::from_json(root, request);
    if(not request.itemDefaults.has_value() or request.itemDefaults->size() not_eq 1uz or (*request
    .itemDefaults)[0uz] not_eq "meow" or not request.applyKindSupport.has_value() or not *request.
    applyKindSupport)
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