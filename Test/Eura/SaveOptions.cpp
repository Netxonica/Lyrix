// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/SaveOptions.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"includeText\":true}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::SaveOptions request;
    Eura::from_json(root, request);
    if(not request.includeText.has_value() or not *request.includeText)
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