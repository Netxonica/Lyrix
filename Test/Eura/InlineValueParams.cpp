// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/InlineValueParams.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"workDoneToken\":\"meow\",\"textDocument\":{\"uri\":\"meow.extension\"},\"range\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}},\"context\":{\"frameId\":-67,\"stoppedLocation\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}}}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::InlineValueParams request;
    Eura::from_json(root, request);
    if(not request.workDoneToken.has_value() or not std::holds_alternative<std::string>(*request.
    workDoneToken) or std::get<std::string>(*request.workDoneToken) not_eq "meow" or request.
    textDocument.uri not_eq "meow.extension" or request.range.start.line not_eq 0u or request.range
    .start.character not_eq 0u or request.range.end.line not_eq 42u or request.range.end.character
    not_eq 67u or request.context.frameId not_eq -67 or request.context.stoppedLocation.start.line
    not_eq 0u or request.context.stoppedLocation.start.character not_eq 0u or request.context.
    stoppedLocation.end.line not_eq 42u or request.context.stoppedLocation.end.character not_eq 67u
    )
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