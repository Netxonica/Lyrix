// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CompletionItemApplyKinds.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"commitCharacters\":1,\"data\":2}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::CompletionItemApplyKinds request;
    Eura::from_json(root, request);
    if(not request.commitCharacters.has_value() or *request.commitCharacters not_eq Eura::ApplyKind
    ::Replace or not request.data.has_value() or *request.data not_eq Eura::ApplyKind::Merge)
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