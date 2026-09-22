// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DocumentHighlight.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"range\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}},\"kind\":3}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::DocumentHighlight request;
    Eura::from_json(root, request);
    if(request.range.start.line not_eq 0u or request.range.start.character not_eq 0u or request.
    range.end.line not_eq 42u or request.range.end.character not_eq 67u or not request.kind.
    has_value() or *request.kind not_eq Eura::DocumentHighlightKind::Write)
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