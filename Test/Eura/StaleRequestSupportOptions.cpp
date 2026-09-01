// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/StaleRequestSupportOptions.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"cancel\":true,\"retryOnContentModified\":[\"meow\"]}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::StaleRequestSupportOptions request;
    Eura::from_json(root, request);
    if(not request.cancel or request.retryOnContentModified.size() not_eq 1uz or request.
    retryOnContentModified[0uz] not_eq "meow")
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