// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/OptionalVersionedTextDocumentIdentifier.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"uri\":\"meow.extension\",\"version\":null}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::OptionalVersionedTextDocumentIdentifier request;
    Eura::from_json(root, request);
    if(request.uri not_eq "meow.extension" or not std::holds_alternative<std::nullptr_t>(request.
    version))
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