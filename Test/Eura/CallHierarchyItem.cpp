// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Message.hpp"
#include "Eura/CallHierarchyItem.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"name\":\"meow\",\"kind\":12,\"tags\":[1],\"detail\":\"nya\",\"range\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}},\"selectionRange\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}},\"data\":{\"jsonrpc\":\"2.0\"}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::CallHierarchyItem request;
    Eura::from_json(root, request);
    if(request.name not_eq "meow" or request.kind not_eq Eura::SymbolKind::Function or not request.
    tags.has_value() or request.tags->size() not_eq 1uz or (*request.tags)[0uz] not_eq Eura::
    SymbolTag::Deprecated or not request.detail.has_value() or *request.detail not_eq "nya" or
    request.range.start.line not_eq 0u or request.range.start.character not_eq 0u or request.range.
    end.line not_eq 42u or request.range.end.character not_eq 67u or request.selectionRange.start.
    line not_eq 0u or request.selectionRange.start.character not_eq 0u or request.selectionRange.
    end.line not_eq 42u or request.selectionRange.end.character not_eq 67u or not request.data.
    has_value())
        return false;
    Eura::Message message;
    Eura::from_json(*request.data, message);
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