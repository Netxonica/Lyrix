// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DocumentSymbolOptions.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"workDoneProgress\":true,\"label\":\"meow\"}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::DocumentSymbolOptions request;
    Eura::from_json(root, request);
    if(not request.workDoneProgress.has_value() or not *request.workDoneProgress or not request.
    label.has_value() or *request.label not_eq "meow")
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