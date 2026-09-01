// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/GeneralClientCapabilities.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"staleRequestSupport\":{\"cancel\":true,\"retryOnContentModified\":[\"meow\"]},\"regularExpressions\":{\"engine\":\"ES2020\",\"version\":\"6.7\"},\"markdown\":{\"parser\":\"lyrix\",\"version\":\"67\",\"allowedTags\":[\"meow\",\"nya\"]},\"positionEncodings\":[\"utf-8\"]}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::GeneralClientCapabilities request;
    Eura::from_json(root, request);
    if(not request.staleRequestSupport.has_value() or not request.staleRequestSupport->cancel or
    request.staleRequestSupport->retryOnContentModified.size() not_eq 1uz or request.
    staleRequestSupport->retryOnContentModified[0uz] not_eq "meow" or not request.
    regularExpressions.has_value() or request.regularExpressions->engine not_eq Eura::ES2020 or
    request.regularExpressions->version not_eq "6.7" or not request.markdown.has_value() or request
    .markdown->parser not_eq "lyrix" or not request.markdown->version.has_value() or *request.
    markdown->version not_eq "67" or not request.markdown->allowedTags.has_value() or request.
    markdown->allowedTags->size() not_eq 2uz or (*request.markdown->allowedTags)[0uz] not_eq "meow"
    or (*request.markdown->allowedTags)[1uz] not_eq "nya" or not request.positionEncodings.
    has_value() or request.positionEncodings->size() not_eq 1uz or (*request.positionEncodings)[0uz
    ] not_eq Eura::UTF8)
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