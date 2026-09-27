// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Message.hpp"
#include "Eura/ExecuteCommandParams.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"workDoneToken\":\"meow\",\"command\":\"nya\",\"arguments\":[{\"jsonrpc\":\"2.0\"}]}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::ExecuteCommandParams request;
    Eura::from_json(root, request);
    if(not request.workDoneToken.has_value() or not std::holds_alternative<std::string>(*request.
    workDoneToken) or std::get<std::string>(*request.workDoneToken) not_eq "meow" or request.
    command not_eq "nya" or not request.arguments.has_value() or request.arguments->size() not_eq
    1uz)
        return false;
    Eura::Message message;
    Eura::from_json((*request.arguments)[0uz], message);
    if(message.jsonrpc not_eq "2.0")
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