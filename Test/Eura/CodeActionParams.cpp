// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CodeActionParams.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"workDoneToken\":\"meow\",\"partialResultToken\":\"meow\",\"textDocument\":{\"uri\":\"meow.extension\"},\"range\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}},\"context\":{\"diagnostics\":[],\"only\":[\"\"],\"triggerKind\":2}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::CodeActionParams request;
    Eura::from_json(root, request);
    if(not request.workDoneToken.has_value() or not std::holds_alternative<std::string>(*request.
    workDoneToken) or std::get<std::string>(*request.workDoneToken) not_eq "meow" or not request.
    partialResultToken.has_value() or not std::holds_alternative<std::string>(*request.
    partialResultToken) or std::get<std::string>(*request.partialResultToken) not_eq "meow" or
    request.textDocument.uri not_eq "meow.extension" or request.range.start.line not_eq 0u or
    request.range.start.character not_eq 0u or request.range.end.line not_eq 42u or request.range.
    end.character not_eq 67u or not request.context.diagnostics.empty() or not request.context.only
    .has_value() or request.context.only->size() not_eq 1uz or (*request.context.only)[0uz] not_eq
    "" or not request.context.triggerKind.has_value() or *request.context.triggerKind not_eq Eura::
    CodeActionTriggerKind::Automatic)
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