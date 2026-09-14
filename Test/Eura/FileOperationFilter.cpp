// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/FileOperationFilter.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"scheme\":\"meow\",\"pattern\":{\"glob\":\"meow\",\"matches\":\"file\",\"options\":{\"ignoreCase\":true}}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::FileOperationFilter request;
    Eura::from_json(root, request);
    if(not request.scheme.has_value() or *request.scheme not_eq "meow" or request.pattern.glob
    not_eq "meow" or not request.pattern.matches.has_value() or *request.pattern.matches not_eq
    Eura::File or not request.pattern.options.has_value() or not request.pattern.options->
    ignoreCase.has_value() or not *request.pattern.options->ignoreCase)
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