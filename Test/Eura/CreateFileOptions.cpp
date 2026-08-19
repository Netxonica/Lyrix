// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CreateFileOptions.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"overwrite\":true,\"ignoreIfExists\":true}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::CreateFileOptions request;
    Eura::from_json(root, request);
    if(not request.overwrite.has_value() or not *request.overwrite or not request.ignoreIfExists.
    has_value() or not *request.ignoreIfExists)
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