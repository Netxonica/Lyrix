// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Message.hpp"
#include "Eura/CodeAction.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"title\":\"meow\",\"kind\":\"quickfix\",\"diagnostics\":[],\"isPreferred\":true,\"disabled\":{\"reason\":\"meow\"},\"command\":{\"title\":\"meow\",\"tooltip\":\"nya\",\"command\":\"operation:cute\",\"arguments\":[{\"jsonrpc\":\"2.0\"}]},\"data\":{\"jsonrpc\":\"2.0\"},\"tags\":[1]}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::CodeAction request;
    Eura::from_json(root, request);
    if(request.title not_eq "meow" or not request.kind.has_value() or *request.kind not_eq Eura::
    QuickFix or not request.diagnostics.has_value() or not request.diagnostics->empty() or not
    request.isPreferred.has_value() or not *request.isPreferred or not request.disabled.has_value()
    or request.disabled->reason not_eq "meow" or request.edit.has_value() or not request.command.
    has_value() or request.command->title not_eq "meow" or not request.command->tooltip.has_value()
    or *request.command->tooltip not_eq "nya" or request.command->command not_eq "operation:cute"
    or not request.command->arguments.has_value() or request.command->arguments->size() not_eq 1uz)
        return false;
    Eura::Message command;
    from_json((*request.command->arguments)[0uz], command);
    if(command.jsonrpc not_eq "2.0")
        return false;
    Eura::Message message;
    from_json(*request.data, message);
    if(message.jsonrpc not_eq "2.0" or not request.tags.has_value() or request.tags->size() not_eq
    1uz or (*request.tags)[0uz] not_eq Eura::CodeActionTag::LLMGenerated)
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