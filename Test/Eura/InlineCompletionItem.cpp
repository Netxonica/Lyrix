// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Message.hpp"
#include "Eura/InlineCompletionItem.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"insertText\":\"nya\",\"filterText\":\"meow\",\"range\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}},\"command\":{\"title\":\"meow\",\"tooltip\":\"nya\",\"command\":\"operation:cute\",\"arguments\":[{\"jsonrpc\":\"2.0\"}]}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::InlineCompletionItem request;
    Eura::from_json(root, request);
    if(not std::holds_alternative<std::string>(request.insertText) or std::get<std::string>(request
    .insertText) not_eq "nya" or not request.filterText.has_value() or *request.filterText not_eq
    "meow" or not request.range.has_value() or request.range->start.line not_eq 0u or request.range
    ->start.character not_eq 0u or request.range->end.line not_eq 42u or request.range->end.
    character not_eq 67u or not request.command.has_value() or request.command->title not_eq "meow"
    or not request.command->tooltip.has_value() or *request.command->tooltip not_eq "nya" or
    request.command->command not_eq "operation:cute" or not request.command->arguments.has_value()
    or request.command->arguments->size() not_eq 1uz)
        return false;
    Eura::Message message;
    from_json((*request.command->arguments)[0uz], message);
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