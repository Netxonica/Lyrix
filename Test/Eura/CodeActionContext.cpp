// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CodeActionContext.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"diagnostics\":[],\"only\":[\"\"],\"triggerKind\":2}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::CodeActionContext request;
    Eura::from_json(root, request);
    if(not request.diagnostics.empty() or not request.only.has_value() or request.only->size()
    not_eq 1uz or (*request.only)[0uz] not_eq "" or not request.triggerKind.has_value() or *request
    .triggerKind not_eq Eura::CodeActionTriggerKind::Automatic)
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