// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/FileOperationPatternOptions.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"ignoreCase\":true}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::FileOperationPatternOptions request;
    Eura::from_json(root, request);
    if(not request.ignoreCase.has_value() or not *request.ignoreCase)
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