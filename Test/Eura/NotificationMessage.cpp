// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/NotificationMessage.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"jsonrpc\":\"2.0\",\"method\":\"nya\",\"params\":{\"jsonrpc\":\"2.0\"}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::NotificationMessage request;
    Eura::from_json(root, request);
    if(request.jsonrpc not_eq "2.0" or request.method not_eq "nya" or not request.params.has_value(
    ))
        return false;
    Eura::Message message;
    Eura::from_json(*request.params, message);
    if(message.jsonrpc not_eq "2.0")
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