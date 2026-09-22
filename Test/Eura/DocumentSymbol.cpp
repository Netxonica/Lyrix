// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DocumentSymbol.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"name\":\"meow\",\"detail\":\"nya\",\"kind\":5,\"tags\":[1],\"range\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}},\"selectionRange\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}},\"children\":[{\"name\":\"meow\",\"detail\":\"nya\",\"kind\":5,\"tags\":[1],\"range\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}},\"selectionRange\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}}}]}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::DocumentSymbol request;
    Eura::from_json(root, request);
    if(request.name not_eq "meow" or not request.detail.has_value() or *request.detail not_eq "nya"
    or request.kind not_eq Eura::SymbolKind::Class or not request.tags.has_value() or request.tags
    ->size() not_eq 1uz or (*request.tags)[0uz] not_eq Eura::SymbolTag::Deprecated or request.range
    .start.line not_eq 0u or request.range.start.character not_eq 0u or request.range.end.line
    not_eq 42u or request.range.end.character not_eq 67u or request.selectionRange.start.line
    not_eq 0u or request.selectionRange.start.character not_eq 0u or request.selectionRange.end.
    line not_eq 42u or request.selectionRange.end.character not_eq 67u or not request.children.
    has_value() or request.children->size() not_eq 1uz or (*request.children)[0uz].name not_eq
    "meow" or not (*request.children)[0uz].detail.has_value() or *(*request.children)[0uz].detail
    not_eq "nya" or (*request.children)[0uz].kind not_eq Eura::SymbolKind::Class or not (*request.
    children)[0uz].tags.has_value() or (*request.children)[0uz].tags->size() not_eq 1uz or (*(*
    request.children)[0uz].tags)[0uz] not_eq Eura::SymbolTag::Deprecated or (*request.children)[0uz
    ].range.start.line not_eq 0u or (*request.children)[0uz].range.start.character not_eq 0u or (*
    request.children)[0uz].range.end.line not_eq 42u or (*request.children)[0uz].range.end.
    character not_eq 67u or (*request.children)[0uz].selectionRange.start.line not_eq 0u or (*
    request.children)[0uz].selectionRange.start.character not_eq 0u or (*request.children)[0uz].
    selectionRange.end.line not_eq 42u or (*request.children)[0uz].selectionRange.end.character
    not_eq 67u or (*request.children)[0uz].children.has_value())
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