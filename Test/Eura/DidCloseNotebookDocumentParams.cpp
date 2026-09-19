// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DidCloseNotebookDocumentParams.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"notebookDocument\":{\"uri\":\"meow.extension\"},\"cellTextDocuments\":[{\"uri\":\"meow.extension\"}]}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::DidCloseNotebookDocumentParams request;
    Eura::from_json(root, request);
    if(request.notebookDocument.uri not_eq "meow.extension" or request.cellTextDocuments.size()
    not_eq 1uz or request.cellTextDocuments[0uz].uri not_eq "meow.extension")
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