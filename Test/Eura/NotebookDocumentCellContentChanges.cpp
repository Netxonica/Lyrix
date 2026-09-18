// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/NotebookDocumentCellContentChanges.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"document\":{\"uri\":\"meow.extension\",\"version\":67},\"changes\":[{\"text\":\"meow meow\"}]}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::NotebookDocumentCellContentChanges request;
    Eura::from_json(root, request);
    if(request.document.uri not_eq "meow.extension" or request.document.version not_eq 67 or
    request.changes.size() not_eq 1uz or not std::holds_alternative<Eura::
    TextDocumentContentChangeWholeDocument>(request.changes[0uz]))
        return false;
    const Eura::TextDocumentContentChangeWholeDocument& changes = std::get<Eura::
    TextDocumentContentChangeWholeDocument>(request.changes[0uz]);
    if(changes.text not_eq "meow meow")
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