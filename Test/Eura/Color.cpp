// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Color.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"red\":0,\"green\":0,\"blue\":0,\"alpha\":0}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::Color request;
    Eura::from_json(root, request);
    if(request.red not_eq 0. or request.green not_eq 0. or request.blue not_eq 0. or request.alpha
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