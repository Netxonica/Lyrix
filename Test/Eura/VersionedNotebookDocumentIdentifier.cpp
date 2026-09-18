// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/VersionedNotebookDocumentIdentifier.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"version\":67,\"uri\":\"meow.extension\"}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::VersionedNotebookDocumentIdentifier request;
    Eura::from_json(root, request);
    if(request.version not_eq 67 or request.uri not_eq "meow.extension")
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