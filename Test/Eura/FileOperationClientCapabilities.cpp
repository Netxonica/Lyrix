// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/FileOperationClientCapabilities.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"dynamicRegistration\":true,\"didCreate\":true,\"willCreate\":true,\"didRename\":true,\"willRename\":true,\"didDelete\":true,\"willDelete\":true}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::FileOperationClientCapabilities request;
    Eura::from_json(root, request);
    if(not request.dynamicRegistration.has_value() or not *request.dynamicRegistration or not
    request.didCreate.has_value() or not *request.didCreate or not request.willCreate.has_value()
    or not *request.willCreate or not request.didRename.has_value() or not *request.didRename or
    not request.willRename.has_value() or not *request.willRename or not request.didDelete.
    has_value() or not *request.didDelete or not request.willDelete.has_value() or not *request.
    willDelete)
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