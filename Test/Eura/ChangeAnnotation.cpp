// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ChangeAnnotation.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"label\":\"meow\",\"needsConfirmation\":true,\"description\":\"meow nya\"}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::ChangeAnnotation request;
    Eura::from_json(root, request);
    if(request.label not_eq "meow" or not request.needsConfirmation.has_value() or not *request.
    needsConfirmation or not request.description.has_value() or *request.description not_eq
    "meow nya")
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