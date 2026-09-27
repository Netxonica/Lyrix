// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ApplyWorkspaceEditResult.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"applied\":true,\"failureReason\":\"meow\",\"failedChange\":67}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::ApplyWorkspaceEditResult request;
    Eura::from_json(root, request);
    if(not request.applied or not request.failureReason.has_value() or *request.failureReason
    not_eq "meow" or not request.failedChange.has_value() or *request.failedChange not_eq 67u)
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