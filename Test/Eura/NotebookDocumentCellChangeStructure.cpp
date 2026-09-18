// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Message.hpp"
#include "Eura/NotebookDocumentCellChangeStructure.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"array\":{\"start\":67,\"deleteCount\":42,\"cells\":[{\"kind\":2,\"document\":\"meow.extension\",\"metadata\":{\"jsonrpc\":\"2.0\"},\"executionSummary\":{\"executionOrder\":67,\"success\":true}}]},\"didOpen\":[{\"uri\":\"meow.extension\",\"languageId\":\"lyrix\",\"version\":67,\"text\":\"meow nya\"}],\"didClose\":[{\"uri\":\"meow.extension\"}]}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::NotebookDocumentCellChangeStructure request;
    Eura::from_json(root, request);
    if(request.array.start not_eq 67u or request.array.deleteCount not_eq 42u or not request.array.
    cells.has_value() or request.array.cells->size() not_eq 1uz)
        return false;
    const Eura::NotebookCell& cell = (*request.array.cells)[0uz];
    if(cell.kind not_eq Eura::NotebookCellKind::Code or cell.document not_eq "meow.extension" or
    not cell.metadata.has_value())
        return false;
    Eura::Message message;
    Eura::from_json(*cell.metadata, message);
    if(message.jsonrpc not_eq "2.0" or not cell.executionSummary.has_value() or cell.
    executionSummary->executionOrder not_eq 67u or not cell.executionSummary->success.has_value()
    or not *cell.executionSummary->success or not request.didOpen.has_value() or request.didOpen->
    size() not_eq 1uz)
        return false;
    const Eura::TextDocumentItem item = (*request.didOpen)[0uz];
    if(item.uri not_eq "meow.extension" or item.languageId not_eq "lyrix" or item.version not_eq 67
    or item.text not_eq "meow nya" or not request.didClose.has_value() or request.didClose->size()
    not_eq 1uz or (*request.didClose)[0uz].uri not_eq "meow.extension")
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