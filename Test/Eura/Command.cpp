// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Message.hpp"
#include "Eura/Command.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"title\":\"meow\",\"tooltip\":\"nya\",\"command\":\"operation:cute\",\"arguments\":[{\"jsonrpc\":\"2.0\"}]}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::Command request;
    Eura::from_json(root, request);
    if(request.title not_eq "meow" or not request.tooltip.has_value() or *request.tooltip not_eq
    "nya" or request.command not_eq "operation:cute" or not request.arguments.has_value() or
    request.arguments->size() not_eq 1uz)
        return false;
    Eura::Message message;
    from_json((*request.arguments)[0uz], message);
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