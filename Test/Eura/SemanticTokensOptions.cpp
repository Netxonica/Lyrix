// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/SemanticTokensOptions.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"workDoneProgress\":true,\"legend\":{\"tokenTypes\":[\"meow\"],\"tokenModifiers\":[\"nya\"]},\"range\":{},\"full\":{\"delta\":true}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::SemanticTokensOptions request;
    Eura::from_json(root, request);
    if(not request.workDoneProgress.has_value() or not *request.workDoneProgress or request.legend.
    tokenTypes.size() not_eq 1uz or request.legend.tokenTypes[0uz] not_eq "meow" or request.legend.
    tokenModifiers.size() not_eq 1uz or request.legend.tokenModifiers[0uz] not_eq "nya" or not
    request.range.has_value() or not std::holds_alternative<Eura::Empty>(*request.range) or not
    request.full.has_value() or not std::holds_alternative<Eura::SemanticTokensFullDelta>(*request.
    full))
        return false;
    const Eura::SemanticTokensFullDelta& full = std::get<Eura::SemanticTokensFullDelta>(*request.
    full);
    if(not full.delta.has_value() or not *full.delta)
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