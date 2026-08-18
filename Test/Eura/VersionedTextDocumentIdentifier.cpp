// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/VersionedTextDocumentIdentifier.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"uri\":\"meow.extension\",\"version\":67}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::VersionedTextDocumentIdentifier request;
    Eura::from_json(root, request);
    if(request.uri not_eq "meow.extension" or request.version not_eq 67)
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