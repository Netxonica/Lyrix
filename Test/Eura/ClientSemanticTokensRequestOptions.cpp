// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ClientSemanticTokensRequestOptions.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"range\":{},\"full\":{\"delta\":true}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::ClientSemanticTokensRequestOptions request;
    Eura::from_json(root, request);
    if(not request.range.has_value() or not std::holds_alternative<Eura::Empty>(*request.range) or
    not request.full.has_value() or not std::holds_alternative<Eura::
    ClientSemanticTokensRequestFullDelta>(*request.full))
        return false;
    const Eura::ClientSemanticTokensRequestFullDelta& delta = std::get<Eura::
    ClientSemanticTokensRequestFullDelta>(*request.full);
    if(not delta.delta.has_value() or not *delta.delta)
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