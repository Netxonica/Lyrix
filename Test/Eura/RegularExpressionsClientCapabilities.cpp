// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/RegularExpressionsClientCapabilities.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"engine\":\"ES2020\",\"version\":\"6.7\"}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::RegularExpressionsClientCapabilities request;
    Eura::from_json(root, request);
    if(request.engine not_eq Eura::ES2020 or request.version not_eq "6.7")
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