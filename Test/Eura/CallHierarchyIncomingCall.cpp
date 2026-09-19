// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Message.hpp"
#include "Eura/CallHierarchyIncomingCall.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"from\":{\"name\":\"meow\",\"kind\":12,\"tags\":[1],\"detail\":\"nya\",\"range\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}},\"selectionRange\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}},\"data\":{\"jsonrpc\":\"2.0\"}},\"fromRanges\":[{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}}]}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::CallHierarchyIncomingCall request;
    Eura::from_json(root, request);
    if(request.from.name not_eq "meow" or request.from.kind not_eq Eura::SymbolKind::Function or
    not request.from.tags.has_value() or request.from.tags->size() not_eq 1uz or (*request.from.
    tags)[0uz] not_eq Eura::SymbolTag::Deprecated or not request.from.detail.has_value() or *
    request.from.detail not_eq "nya" or request.from.range.start.line not_eq 0u or request.from.
    range.start.character not_eq 0u or request.from.range.end.line not_eq 42u or request.from.range
    .end.character not_eq 67u or request.from.selectionRange.start.line not_eq 0u or request.from.
    selectionRange.start.character not_eq 0u or request.from.selectionRange.end.line not_eq 42u or
    request.from.selectionRange.end.character not_eq 67u or not request.from.data.has_value())
        return false;
    Eura::Message message;
    Eura::from_json(*request.from.data, message);
    if(message.jsonrpc not_eq "2.0" or request.fromRanges.size() not_eq 1uz or request.fromRanges[
    0uz].start.line not_eq 0u or request.fromRanges[0uz].start.character not_eq 0u or request.
    fromRanges[0uz].end.line not_eq 42u or request.fromRanges[0uz].end.character not_eq 67u)
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