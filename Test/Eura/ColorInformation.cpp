// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ColorInformation.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"range\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}},\"color\":{\"red\":0,\"green\":0,\"blue\":0,\"alpha\":0}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::ColorInformation request;
    Eura::from_json(root, request);
    if(request.range.start.line not_eq 0u or request.range.start.character not_eq 0u or request.
    range.end.line not_eq 42u or request.range.end.character not_eq 67u or request.color.red not_eq
    0. or request.color.green not_eq 0. or request.color.blue not_eq 0. or request.color.alpha
    not_eq 0.)
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