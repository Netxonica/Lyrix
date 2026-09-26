// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/InlineCompletionContext.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"triggerKind\":2,\"selectedCompletionInfo\":{\"range\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}},\"text\":\"nya\"}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::InlineCompletionContext request;
    Eura::from_json(root, request);
    if(request.triggerKind not_eq Eura::InlineCompletionTriggerKind::Automatic or not request.
    selectedCompletionInfo.has_value() or request.selectedCompletionInfo->range.start.line not_eq
    0u or request.selectedCompletionInfo->range.start.character not_eq 0u or request.
    selectedCompletionInfo->range.end.line not_eq 42u or request.selectedCompletionInfo->range.end.
    character not_eq 67u or request.selectedCompletionInfo->text not_eq "nya")
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