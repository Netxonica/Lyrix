// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CompletionOptions.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"workDoneProgress\":true,\"triggerCharacters\":[\"meow\"],\"allCommitCharacters\":[\"nya\"],\"resolveProvider\":true,\"completionItem\":{\"labelDetailsSupport\":true}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::CompletionOptions request;
    Eura::from_json(root, request);
    if(not request.workDoneProgress.has_value() or not *request.workDoneProgress or not request.
    triggerCharacters.has_value() or request.triggerCharacters->size() not_eq 1uz or (*request.
    triggerCharacters)[0uz] not_eq "meow" or not request.allCommitCharacters.has_value() or request
    .allCommitCharacters->size() not_eq 1uz or (*request.allCommitCharacters)[0uz] not_eq "nya" or
    not request.resolveProvider.has_value() or not *request.resolveProvider or not request.
    completionItem.has_value() or not request.completionItem->labelDetailsSupport.has_value() or
    not *request.completionItem->labelDetailsSupport)
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