// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/FileOperationOptions.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"didCreate\":{\"filters\":[{\"scheme\":\"meow\",\"pattern\":{\"glob\":\"meow\",\"matches\":\"file\",\"options\":{\"ignoreCase\":true}}}]},\"willCreate\":{\"filters\":[{\"scheme\":\"meow\",\"pattern\":{\"glob\":\"meow\",\"matches\":\"file\",\"options\":{\"ignoreCase\":true}}}]},\"didRename\":{\"filters\":[{\"scheme\":\"meow\",\"pattern\":{\"glob\":\"meow\",\"matches\":\"file\",\"options\":{\"ignoreCase\":true}}}]},\"willRename\":{\"filters\":[{\"scheme\":\"meow\",\"pattern\":{\"glob\":\"meow\",\"matches\":\"file\",\"options\":{\"ignoreCase\":true}}}]},\"didDelete\":{\"filters\":[{\"scheme\":\"meow\",\"pattern\":{\"glob\":\"meow\",\"matches\":\"file\",\"options\":{\"ignoreCase\":true}}}]},\"willDelete\":{\"filters\":[{\"scheme\":\"meow\",\"pattern\":{\"glob\":\"meow\",\"matches\":\"file\",\"options\":{\"ignoreCase\":true}}}]}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::FileOperationOptions request;
    Eura::from_json(root, request);
    if(not request.didCreate.has_value() or request.didCreate->filters.size() not_eq 1uz)
        return false;
    {
        const Eura::FileOperationFilter& filter = request.didCreate->filters[0uz];
        if(not filter.scheme.has_value() or *filter.scheme not_eq "meow" or filter.pattern.glob
        not_eq "meow" or not filter.pattern.matches.has_value() or *filter.pattern.matches not_eq
        Eura::File or not filter.pattern.options.has_value() or not filter.pattern.options->
        ignoreCase.has_value() or not *filter.pattern.options->ignoreCase or not request.willCreate
        .has_value() or request.willCreate->filters.size() not_eq 1uz)
            return false;
    }
    {
        const Eura::FileOperationFilter& filter = request.willCreate->filters[0uz];
        if(not filter.scheme.has_value() or *filter.scheme not_eq "meow" or filter.pattern.glob
        not_eq "meow" or not filter.pattern.matches.has_value() or *filter.pattern.matches not_eq
        Eura::File or not filter.pattern.options.has_value() or not filter.pattern.options->
        ignoreCase.has_value() or not *filter.pattern.options->ignoreCase or not request.didRename.
        has_value() or request.didRename->filters.size() not_eq 1uz)
            return false;
    }
    {
        const Eura::FileOperationFilter& filter = request.didRename->filters[0uz];
        if(not filter.scheme.has_value() or *filter.scheme not_eq "meow" or filter.pattern.glob
        not_eq "meow" or not filter.pattern.matches.has_value() or *filter.pattern.matches not_eq
        Eura::File or not filter.pattern.options.has_value() or not filter.pattern.options->
        ignoreCase.has_value() or not *filter.pattern.options->ignoreCase or not request.willRename
        .has_value() or request.willRename->filters.size() not_eq 1uz)
            return false;
    }
    {
        const Eura::FileOperationFilter& filter = request.willRename->filters[0uz];
        if(not filter.scheme.has_value() or *filter.scheme not_eq "meow" or filter.pattern.glob
        not_eq "meow" or not filter.pattern.matches.has_value() or *filter.pattern.matches not_eq
        Eura::File or not filter.pattern.options.has_value() or not filter.pattern.options->
        ignoreCase.has_value() or not *filter.pattern.options->ignoreCase or not request.didDelete.
        has_value() or request.didDelete->filters.size() not_eq 1uz)
            return false;
    }
    {
        const Eura::FileOperationFilter& filter = request.didDelete->filters[0uz];
        if(not filter.scheme.has_value() or *filter.scheme not_eq "meow" or filter.pattern.glob
        not_eq "meow" or not filter.pattern.matches.has_value() or *filter.pattern.matches not_eq
        Eura::File or not filter.pattern.options.has_value() or not filter.pattern.options->
        ignoreCase.has_value() or not *filter.pattern.options->ignoreCase or not request.willDelete
        .has_value() or request.willDelete->filters.size() not_eq 1uz)
            return false;
    }
    {
        const Eura::FileOperationFilter& filter = request.willDelete->filters[0uz];
        if(not filter.scheme.has_value() or *filter.scheme not_eq "meow" or filter.pattern.glob
        not_eq "meow" or not filter.pattern.matches.has_value() or *filter.pattern.matches not_eq
        Eura::File or not filter.pattern.options.has_value() or not filter.pattern.options->
        ignoreCase.has_value() or not *filter.pattern.options->ignoreCase)
            return false;
    }
    nlohmann::json response;
    Eura::to_json(response, request);
    return response.dump() == root.dump();
}

int main()
{
    return not lyrix_test();
}

#endif