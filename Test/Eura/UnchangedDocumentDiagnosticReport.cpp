// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/UnchangedDocumentDiagnosticReport.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"kind\":\"unchanged\",\"resultId\":\"meow\"}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::UnchangedDocumentDiagnosticReport request;
    Eura::from_json(root, request);
    if(request.kind not_eq Eura::Unchanged or request.resultId not_eq "meow")
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