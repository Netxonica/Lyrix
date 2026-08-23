// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ClientCodeActionLiteralOptions.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"codeActionKind\":{\"valueSet\":[\"source\"]}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::ClientCodeActionLiteralOptions request;
    Eura::from_json(root, request);
    if(request.codeActionKind.valueSet.size() not_eq 1uz or request.codeActionKind.valueSet[0uz]
    not_eq Eura::Source)
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