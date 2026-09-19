// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Message.hpp"
#include "Eura/CallHierarchyIncomingCallsParams.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"workDoneToken\":\"meow\",\"partialResultToken\":\"meow\",\"item\":{\"name\":\"meow\",\"kind\":12,\"tags\":[1],\"detail\":\"nya\",\"range\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}},\"selectionRange\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}},\"data\":{\"jsonrpc\":\"2.0\"}}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::CallHierarchyIncomingCallsParams request;
    Eura::from_json(root, request);
    if(not request.workDoneToken.has_value() or not std::holds_alternative<std::string>(*request.
    workDoneToken) or std::get<std::string>(*request.workDoneToken) not_eq "meow" or not request.
    partialResultToken.has_value() or not std::holds_alternative<std::string>(*request.
    partialResultToken) or std::get<std::string>(*request.partialResultToken) not_eq "meow" or
    request.item.name not_eq "meow" or request.item.kind not_eq Eura::SymbolKind::Function or not
    request.item.tags.has_value() or request.item.tags->size() not_eq 1uz or (*request.item.tags)[
    0uz] not_eq Eura::SymbolTag::Deprecated or not request.item.detail.has_value() or *request.item
    .detail not_eq "nya" or request.item.range.start.line not_eq 0u or request.item.range.start.
    character not_eq 0u or request.item.range.end.line not_eq 42u or request.item.range.end.
    character not_eq 67u or request.item.selectionRange.start.line not_eq 0u or request.item.
    selectionRange.start.character not_eq 0u or request.item.selectionRange.end.line not_eq 42u or
    request.item.selectionRange.end.character not_eq 67u or not request.item.data.has_value())
        return false;
    Eura::Message message;
    Eura::from_json(*request.item.data, message);
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