// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Message.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string_view content = "{\"jsonrpc\":\"2.0\"}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::Message request;
    Eura::from_json(root, request);
    if(request.jsonrpc not_eq "2.0")
        return false;
    nlohmann::json response;
    Eura::to_json(response, request);
    return response.dump() == content;
}

int main()
{
    return not lyrix_test();
}

#endif