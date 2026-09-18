// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/TextDocumentContentChangeWholeDocument.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"text\":\"meow meow\"}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::TextDocumentContentChangeWholeDocument request;
    Eura::from_json(root, request);
    if(request.text not_eq "meow meow")
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