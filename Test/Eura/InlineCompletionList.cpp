// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Message.hpp"
#include "Eura/InlineCompletionList.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"items\":[{\"insertText\":\"nya\",\"filterText\":\"meow\",\"range\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}},\"command\":{\"title\":\"meow\",\"tooltip\":\"nya\",\"command\":\"operation:cute\",\"arguments\":[{\"jsonrpc\":\"2.0\"}]}}]}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::InlineCompletionList request;
    Eura::from_json(root, request);
    if(request.items.size() not_eq 1uz or not std::holds_alternative<std::string>(request.items[0uz
    ].insertText) or std::get<std::string>(request.items[0uz].insertText) not_eq "nya" or not
    request.items[0uz].filterText.has_value() or *request.items[0uz].filterText not_eq "meow" or
    not request.items[0uz].range.has_value() or request.items[0uz].range->start.line not_eq 0u or
    request.items[0uz].range->start.character not_eq 0u or request.items[0uz].range->end.line
    not_eq 42u or request.items[0uz].range->end.character not_eq 67u or not request.items[0uz].
    command.has_value() or request.items[0uz].command->title not_eq "meow" or not request.items[0uz
    ].command->tooltip.has_value() or *request.items[0uz].command->tooltip not_eq "nya" or request.
    items[0uz].command->command not_eq "operation:cute" or not request.items[0uz].command->
    arguments.has_value() or request.items[0uz].command->arguments->size() not_eq 1uz)
        return false;
    Eura::Message message;
    from_json((*request.items[0uz].command->arguments)[0uz], message);
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