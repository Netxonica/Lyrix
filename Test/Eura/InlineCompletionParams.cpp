// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/InlineCompletionParams.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"textDocument\":{\"uri\":\"meow.extension\"},\"position\":{\"line\":42,\"character\":67},\"workDoneToken\":\"meow\",\"context\":{\"triggerKind\":2,\"selectedCompletionInfo\":{\"range\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}},\"text\":\"nya\"}}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::InlineCompletionParams request;
    Eura::from_json(root, request);
    if(request.textDocument.uri not_eq "meow.extension" or request.position.line not_eq 42u or
    request.position.character not_eq 67u or not request.workDoneToken.has_value() or not std::
    holds_alternative<std::string>(*request.workDoneToken) or std::get<std::string>(*request.
    workDoneToken) not_eq "meow" or request.context.triggerKind not_eq Eura::
    InlineCompletionTriggerKind::Automatic or not request.context.selectedCompletionInfo.has_value(
    ) or request.context.selectedCompletionInfo->range.start.line not_eq 0u or request.context.
    selectedCompletionInfo->range.start.character not_eq 0u or request.context.
    selectedCompletionInfo->range.end.line not_eq 42u or request.context.selectedCompletionInfo->
    range.end.character not_eq 67u or request.context.selectedCompletionInfo->text not_eq "nya")
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