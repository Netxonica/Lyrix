// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Message.hpp"
#include "Eura/DidChangeNotebookDocumentParams.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"notebookDocument\":{\"version\":67,\"uri\":\"meow.extension\"},\"change\":{\"metadata\":{\"jsonrpc\":\"2.0\"},\"cells\":{\"structure\":{\"array\":{\"start\":67,\"deleteCount\":42,\"cells\":[{\"kind\":2,\"document\":\"meow.extension\",\"metadata\":{\"jsonrpc\":\"2.0\"},\"executionSummary\":{\"executionOrder\":67,\"success\":true}}]},\"didOpen\":[{\"uri\":\"meow.extension\",\"languageId\":\"lyrix\",\"version\":67,\"text\":\"meow nya\"}],\"didClose\":[{\"uri\":\"meow.extension\"}]},\"data\":[{\"kind\":2,\"document\":\"meow.extension\",\"metadata\":{\"jsonrpc\":\"2.0\"},\"executionSummary\":{\"executionOrder\":67,\"success\":true}}],\"textContent\":[{\"document\":{\"uri\":\"meow.extension\",\"version\":67},\"changes\":[{\"text\":\"meow meow\"}]}]}}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::DidChangeNotebookDocumentParams request;
    Eura::from_json(root, request);
    if(request.notebookDocument.version not_eq 67 or request.notebookDocument.uri not_eq
    "meow.extension" or not request.change.metadata.has_value())
        return false;
    Eura::Message metadata;
    Eura::from_json(*request.change.metadata, metadata);
    if(metadata.jsonrpc not_eq "2.0" or not request.change.cells.has_value() or request.change.
    cells->structure->array.start not_eq 67u or request.change.cells->structure->array.deleteCount
    not_eq 42u or not request.change.cells->structure->array.cells.has_value() or request.change.
    cells->structure->array.cells->size() not_eq 1uz)
        return false;
    const Eura::NotebookCell& cell = (*request.change.cells->structure->array.cells)[0uz];
    if(cell.kind not_eq Eura::NotebookCellKind::Code or cell.document not_eq "meow.extension" or
    not cell.metadata.has_value())
        return false;
    Eura::Message message;
    Eura::from_json(*cell.metadata, message);
    if(message.jsonrpc not_eq "2.0" or not cell.executionSummary.has_value() or cell.
    executionSummary->executionOrder not_eq 67u or not cell.executionSummary->success.has_value()
    or not *cell.executionSummary->success or not request.change.cells->structure->didOpen.
    has_value() or request.change.cells->structure->didOpen->size() not_eq 1uz)
        return false;
    const Eura::TextDocumentItem item = (*request.change.cells->structure->didOpen)[0uz];
    if(item.uri not_eq "meow.extension" or item.languageId not_eq "lyrix" or item.version not_eq 67
    or item.text not_eq "meow nya" or not request.change.cells->structure->didClose.has_value() or
    request.change.cells->structure->didClose->size() not_eq 1uz or (*request.change.cells->
    structure->didClose)[0uz].uri not_eq "meow.extension" or not request.change.cells->data.
    has_value() or request.change.cells->data->size() not_eq 1uz)
        return false;
    const Eura::NotebookCell& cell2 = (*request.change.cells->data)[0uz];
    if(cell2.kind not_eq Eura::NotebookCellKind::Code or cell2.document not_eq "meow.extension" or
    not cell2.metadata.has_value())
        return false;
    Eura::Message message2;
    Eura::from_json(*cell2.metadata, message2);
    if(message2.jsonrpc not_eq "2.0" or not cell2.executionSummary.has_value() or cell2.
    executionSummary->executionOrder not_eq 67u or not cell2.executionSummary->success.has_value()
    or not *cell2.executionSummary->success or not request.change.cells->textContent.has_value() or
    request.change.cells->textContent->size() not_eq 1uz)
        return false;
    const Eura::NotebookDocumentCellContentChanges& changes = (*request.change.cells->textContent)[
    0uz];
    if(changes.document.uri not_eq "meow.extension" or changes.document.version not_eq 67 or
    changes.changes.size() not_eq 1uz or not std::holds_alternative<Eura::
    TextDocumentContentChangeWholeDocument>(changes.changes[0uz]))
        return false;
    const Eura::TextDocumentContentChangeWholeDocument& changess = std::get<Eura::
    TextDocumentContentChangeWholeDocument>(changes.changes[0uz]);
    if(changess.text not_eq "meow meow")
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