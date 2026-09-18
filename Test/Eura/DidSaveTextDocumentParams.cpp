// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DidSaveTextDocumentParams.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"textDocument\":{\"uri\":\"meow.extension\"},\"text\":\"meow nya\"}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::DidSaveTextDocumentParams request;
    Eura::from_json(root, request);
    if(request.textDocument.uri not_eq "meow.extension" or not request.text.has_value() or *request
    .text not_eq "meow nya")
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