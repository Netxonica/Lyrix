// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/WorkspaceFullDocumentDiagnosticReport.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"kind\":\"full\",\"resultId\":\"meow\",\"items\":[],\"uri\":\"meow.extension\",\"version\":null}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::WorkspaceFullDocumentDiagnosticReport request;
    Eura::from_json(root, request);
    if(request.kind not_eq Eura::Full or not request.resultId.has_value() or *request.resultId
    not_eq "meow" or not request.items.empty() or request.uri not_eq "meow.extension" or not std::
    holds_alternative<std::nullptr_t>(request.version))
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