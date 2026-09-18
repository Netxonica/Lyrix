// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Message.hpp"
#include "Eura/NotebookDocument.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"uri\":\"meow.extension\",\"notebookType\":\"meow\",\"version\":67,\"metadata\":{\"jsonrpc\":\"2.0\"},\"cells\":[{\"kind\":2,\"document\":\"meow.extension\",\"metadata\":{\"jsonrpc\":\"2.0\"},\"executionSummary\":{\"executionOrder\":67,\"success\":true}}]}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::NotebookDocument request;
    Eura::from_json(root, request);
    if(request.uri not_eq "meow.extension" or request.notebookType not_eq "meow" or request.version
    not_eq 67 or not request.metadata.has_value())
        return false;
    Eura::Message message;
    Eura::from_json(*request.metadata, message);
    if(message.jsonrpc not_eq "2.0" or request.cells.size() not_eq 1uz)
        return false;
    const Eura::NotebookCell cell = request.cells[0uz];
    if(cell.kind not_eq Eura::NotebookCellKind::Code or cell.document not_eq "meow.extension" or
    not cell.metadata.has_value())
        return false;
    Eura::Message message2;
    Eura::from_json(*cell.metadata, message2);
    if(message2.jsonrpc not_eq "2.0" or not cell.executionSummary.has_value() or cell.
    executionSummary->executionOrder not_eq 67u or not cell.executionSummary->success.has_value()
    or not *cell.executionSummary->success)
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