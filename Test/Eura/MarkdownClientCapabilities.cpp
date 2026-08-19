// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/MarkdownClientCapabilities.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"parser\":\"lyrix\",\"version\":\"67\",\"allowedTags\":[\"meow\",\"nya\"]}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::MarkdownClientCapabilities request;
    Eura::from_json(root, request);
    if(request.parser not_eq "lyrix" or not request.version.has_value() or *request.version not_eq
    "67" or not request.allowedTags.has_value() or request.allowedTags->size() not_eq 2uz or (*
    request.allowedTags)[0uz] not_eq "meow" or (*request.allowedTags)[1uz] not_eq "nya")
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