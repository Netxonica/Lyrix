// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Range.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::Range request;
    Eura::from_json(root, request);
    if(request.start.line not_eq 0u or request.start.character not_eq 0u or request.end.line not_eq
    42u or request.end.character not_eq 67u)
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