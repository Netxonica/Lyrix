// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ShowDocumentParams.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"uri\":\"nya.extension\",\"external\":true,\"takeFocus\":true,\"selection\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::ShowDocumentParams request;
    Eura::from_json(root, request);
    if(request.uri not_eq "nya.extension" or not request.external.has_value() or not *request.
    external or not request.takeFocus.has_value() or not *request.takeFocus or not request.
    selection.has_value() or request.selection->start.line not_eq 0u or request.selection->start.
    character not_eq 0u or request.selection->end.line not_eq 42u or request.selection->end.
    character not_eq 67u)
        return false;
    nlohmann::json response;
    Eura::to_json(response, request);
    return response == root;
}

int main()
{
    return not lyrix_test();
}

#endif