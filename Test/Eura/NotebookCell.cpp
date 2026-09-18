// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Message.hpp"
#include "Eura/NotebookCell.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"kind\":2,\"document\":\"meow.extension\",\"metadata\":{\"jsonrpc\":\"2.0\"},\"executionSummary\":{\"executionOrder\":67,\"success\":true}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::NotebookCell request;
    Eura::from_json(root, request);
    if(request.kind not_eq Eura::NotebookCellKind::Code or request.document not_eq "meow.extension"
    or not request.metadata.has_value())
        return false;
    Eura::Message message;
    Eura::from_json(*request.metadata, message);
    if(message.jsonrpc not_eq "2.0" or not request.executionSummary.has_value() or request.
    executionSummary->executionOrder not_eq 67u or not request.executionSummary->success.has_value(
    ) or not *request.executionSummary->success)
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