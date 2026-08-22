// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/TextDocumentSyncClientCapabilities.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"dynamicRegistration\":true,\"willSave\":true,\"willSaveWaitUntil\":true,\"didSave\":true}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::TextDocumentSyncClientCapabilities request;
    Eura::from_json(root, request);
    if(not request.dynamicRegistration.has_value() or not *request.dynamicRegistration or not
    request.willSave.has_value() or not *request.willSave or not request.willSaveWaitUntil.
    has_value() or not *request.willSaveWaitUntil or not request.didSave.has_value() or not *
    request.didSave)
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