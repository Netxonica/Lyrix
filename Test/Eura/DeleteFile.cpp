// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DeleteFile.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"kind\":\"delete\",\"uri\":\"meow.extension\",\"options\":{\"recursive\":true,\"ignoreIfNotExists\":true},\"annotationId\":\"meow\"}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::DeleteFile request;
    Eura::from_json(root, request);
    if(request.kind not_eq "delete" or request.uri not_eq "meow.extension" or not request.options.
    has_value() or not request.options->recursive.has_value() or not *request.options->recursive or
    not request.options->ignoreIfNotExists.has_value() or not *request.options->ignoreIfNotExists
    or not request.annotationId.has_value() or *request.annotationId not_eq "meow")
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