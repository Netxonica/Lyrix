// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Location.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"uri\":\"meow.extension\",\"range\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::Location request;
    Eura::from_json(root, request);
    if(request.uri not_eq "meow.extension" or request.range.start.line not_eq 0u or request.range.
    start.character not_eq 0u or request.range.end.line not_eq 42u or request.range.end.character
    not_eq 67u)
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