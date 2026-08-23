// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/RenameClientCapabilities.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"dynamicRegistration\":true,\"prepareSupport\":true,\"prepareSupportDefaultBehavior\":1,\"honorsChangeAnnotations\":true}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::RenameClientCapabilities request;
    Eura::from_json(root, request);
    if(not request.dynamicRegistration.has_value() or not *request.dynamicRegistration or not
    request.prepareSupport.has_value() or not *request.prepareSupport or not request.
    prepareSupportDefaultBehavior.has_value() or *request.prepareSupportDefaultBehavior not_eq Eura
    ::PrepareSupportDefaultBehavior::Identifier or not request.honorsChangeAnnotations.has_value()
    or not *request.honorsChangeAnnotations)
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