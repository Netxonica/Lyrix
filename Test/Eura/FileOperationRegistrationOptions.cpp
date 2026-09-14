// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/FileOperationRegistrationOptions.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"filters\":[{\"scheme\":\"meow\",\"pattern\":{\"glob\":\"meow\",\"matches\":\"file\",\"options\":{\"ignoreCase\":true}}}]}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::FileOperationRegistrationOptions request;
    Eura::from_json(root, request);
    if(request.filters.size() not_eq 1uz)
        return false;
    const Eura::FileOperationFilter& filter = request.filters[0uz];
    if(not filter.scheme.has_value() or *filter.scheme not_eq "meow" or filter.pattern.glob not_eq
    "meow" or not filter.pattern.matches.has_value() or *filter.pattern.matches not_eq Eura::File
    or not filter.pattern.options.has_value() or not filter.pattern.options->ignoreCase.has_value()
    or not *filter.pattern.options->ignoreCase)
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