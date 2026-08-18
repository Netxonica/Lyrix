// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Message.hpp"
#include "Eura/ProgressParams.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"token\":\"meow\",\"value\":{\"jsonrpc\":\"2.0\"}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::ProgressParams<nlohmann::json> request;
    Eura::from_json(root, request);
    if(not std::holds_alternative<std::string>(request.token) or std::get<std::string>(request.
    token) not_eq "meow")
        return false;
    Eura::Message message;
    Eura::from_json(request.value, message);
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