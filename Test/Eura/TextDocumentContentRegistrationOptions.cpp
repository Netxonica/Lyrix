// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/TextDocumentContentRegistrationOptions.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"schemes\":[\"meow\"],\"id\":\"meow\"}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::TextDocumentContentRegistrationOptions request;
    Eura::from_json(root, request);
    if(request.schemes.size() not_eq 1uz or request.schemes[0uz] not_eq "meow" or not request.id.
    has_value() or *request.id not_eq "meow")
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