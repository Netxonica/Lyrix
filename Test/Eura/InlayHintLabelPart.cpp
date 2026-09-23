// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Message.hpp"
#include "Eura/InlayHintLabelPart.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"value\":\"meow\",\"tooltip\":\"nya\",\"location\":{\"uri\":\"meow.extension\",\"range\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}}},\"command\":{\"title\":\"meow\",\"tooltip\":\"nya\",\"command\":\"operation:cute\",\"arguments\":[{\"jsonrpc\":\"2.0\"}]}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::InlayHintLabelPart request;
    Eura::from_json(root, request);
    if(request.value not_eq "meow" or not request.tooltip.has_value() or not std::holds_alternative
    <std::string>(*request.tooltip) or std::get<std::string>(*request.tooltip) not_eq "nya" or not
    request.location.has_value() or request.location->uri not_eq "meow.extension" or request.
    location->range.start.line not_eq 0u or request.location->range.start.character not_eq 0u or
    request.location->range.end.line not_eq 42u or request.location->range.end.character not_eq 67u
    or not request.command.has_value() or request.command->title not_eq "meow" or not request.
    command->tooltip.has_value() or *request.command->tooltip not_eq "nya" or request.command->
    command not_eq "operation:cute" or not request.command->arguments.has_value() or request.
    command->arguments->size() not_eq 1uz)
        return false;
    Eura::Message message;
    from_json((*request.command->arguments)[0uz], message);
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