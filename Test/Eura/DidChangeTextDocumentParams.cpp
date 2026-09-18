// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DidChangeTextDocumentParams.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"textDocument\":{\"uri\":\"meow.extension\",\"version\":67},\"contentChanges\":[{\"text\":\"meow meow\"}]}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::DidChangeTextDocumentParams request;
    Eura::from_json(root, request);
    if(request.textDocument.uri not_eq "meow.extension" or request.textDocument.version not_eq 67
    or request.contentChanges.size() not_eq 1uz or not std::holds_alternative<Eura::
    TextDocumentContentChangeWholeDocument>(request.contentChanges[0uz]))
        return false;
    const Eura::TextDocumentContentChangeWholeDocument& contentChange = std::get<Eura::
    TextDocumentContentChangeWholeDocument>(request.contentChanges[0uz]);
    if(contentChange.text not_eq "meow meow")
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