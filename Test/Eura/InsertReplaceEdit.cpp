// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/InsertReplaceEdit.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"newText\":\"meow nya\",\"insert\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}},\"replace\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::InsertReplaceEdit request;
    Eura::from_json(root, request);
    if(request.newText not_eq "meow nya" or request.insert.start.line not_eq 0u or request.insert.
    start.character not_eq 0u or request.insert.end.line not_eq 42u or request.insert.end.character
    not_eq 67u or request.replace.start.line not_eq 0u or request.replace.start.character not_eq 0u
    or request.replace.end.line not_eq 42u or request.replace.end.character not_eq 67u)
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