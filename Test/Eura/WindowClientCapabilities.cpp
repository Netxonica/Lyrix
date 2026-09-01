// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/WindowClientCapabilities.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"workDoneProgress\":true,\"showMessage\":{\"messageActionItem\":{\"additionalPropertiesSupport\":true}},\"showDocument\":{\"support\":true}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::WindowClientCapabilities request;
    Eura::from_json(root, request);
    if(not request.workDoneProgress.has_value() or not *request.workDoneProgress or not request.
    showMessage.has_value() or not request.showMessage->messageActionItem.has_value() or not
    request.showMessage->messageActionItem->additionalPropertiesSupport.has_value() or not *request
    .showMessage->messageActionItem->additionalPropertiesSupport or not request.showDocument.
    has_value() or not request.showDocument->support)
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