// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/TextDocumentSyncOptions.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"openClose\":true,\"change\":2,\"willSave\":true,\"willSaveWaitUntil\":true,\"save\":true}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::TextDocumentSyncOptions request;
    Eura::from_json(root, request);
    if(not request.openClose.has_value() or not *request.openClose or not request.change.has_value(
    ) or *request.change not_eq Eura::TextDocumentSyncKind::Incremental or not request.willSave.
    has_value() or not *request.willSave or not request.willSaveWaitUntil.has_value() or not *
    request.willSaveWaitUntil or not request.save.has_value() or not std::holds_alternative<bool>(*
    request.save) or not std::get<bool>(*request.save))
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