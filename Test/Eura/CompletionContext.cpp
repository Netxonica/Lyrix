// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CompletionContext.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"triggerKind\":3,\"triggerCharacter\":\"meow\"}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::CompletionContext request;
    Eura::from_json(root, request);
    if(request.triggerKind not_eq Eura::CompletionTriggerKind::TriggerForIncompleteCompletions or
    not request.triggerCharacter.has_value() or *request.triggerCharacter not_eq "meow")
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