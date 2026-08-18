// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/TextDocumentItem.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"uri\":\"meow.extension\",\"languageId\":\"lyrix\",\"version\":67,\"text\":\"meow nya\"}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::TextDocumentItem request;
    Eura::from_json(root, request);
    if(request.uri not_eq "meow.extension" or request.languageId not_eq "lyrix" or request.version
    not_eq 67 or request.text not_eq "meow nya")
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