// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/FileOperationPattern.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"glob\":\"meow\",\"matches\":\"file\",\"options\":{\"ignoreCase\":true}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::FileOperationPattern request;
    Eura::from_json(root, request);
    if(request.glob not_eq "meow" or not request.matches.has_value() or *request.matches not_eq
    Eura::File or not request.options.has_value() or not request.options->ignoreCase.has_value() or
    not *request.options->ignoreCase)
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