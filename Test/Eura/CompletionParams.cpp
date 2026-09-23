// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CompletionParams.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"textDocument\":{\"uri\":\"meow.extension\"},\"position\":{\"line\":42,\"character\":67},\"workDoneToken\":\"meow\",\"partialResultToken\":\"meow\",\"context\":{\"triggerKind\":3,\"triggerCharacter\":\"meow\"}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::CompletionParams request;
    Eura::from_json(root, request);
    if(request.textDocument.uri not_eq "meow.extension" or request.position.line not_eq 42u or
    request.position.character not_eq 67u or not request.workDoneToken.has_value() or not std::
    holds_alternative<std::string>(*request.workDoneToken) or std::get<std::string>(*request.
    workDoneToken) not_eq "meow" or not request.partialResultToken.has_value() or not std::
    holds_alternative<std::string>(*request.partialResultToken) or std::get<std::string>(*request.
    partialResultToken) not_eq "meow" or not request.context.has_value() or request.context->
    triggerKind not_eq Eura::CompletionTriggerKind::TriggerForIncompleteCompletions or not request.
    context->triggerCharacter.has_value() or *request.context->triggerCharacter not_eq "meow")
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