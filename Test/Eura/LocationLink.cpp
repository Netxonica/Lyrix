// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/LocationLink.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"originSelectionRange\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}},\"targetUri\":\"meow.extension\",\"targetRange\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}},\"targetSelectionRange\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::LocationLink request;
    Eura::from_json(root, request);
    if(not request.originSelectionRange.has_value() or request.originSelectionRange->start.line
    not_eq 0u or request.originSelectionRange->start.character not_eq 0u or request.
    originSelectionRange->end.line not_eq 42u or request.originSelectionRange->end.character not_eq
    67u or request.targetUri not_eq "meow.extension" or request.targetRange.start.line not_eq 0u or
    request.targetRange.start.character not_eq 0u or request.targetRange.end.line not_eq 42u or
    request.targetRange.end.character not_eq 67u or request.targetSelectionRange.start.line not_eq
    0u or request.targetSelectionRange.start.character not_eq 0u or request.targetSelectionRange.
    end.line not_eq 42u or request.targetSelectionRange.end.character not_eq 67u)
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