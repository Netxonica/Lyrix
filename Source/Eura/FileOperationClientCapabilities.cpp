// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/FileOperationClientCapabilities.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, FileOperationClientCapabilities&
    file_operation_client_capabilities) noexcept -> void
    {
        if(object.contains("dynamicRegistration"))
            file_operation_client_capabilities.dynamicRegistration = object.at(
            "dynamicRegistration").get<bool>();
        if(object.contains("didCreate"))
            file_operation_client_capabilities.didCreate = object.at("didCreate").get<bool>();
        if(object.contains("willCreate"))
            file_operation_client_capabilities.willCreate = object.at("willCreate").get<bool>();
        if(object.contains("didRename"))
            file_operation_client_capabilities.didRename = object.at("didRename").get<bool>();
        if(object.contains("willRename"))
            file_operation_client_capabilities.willRename = object.at("willRename").get<bool>();
        if(object.contains("didDelete"))
            file_operation_client_capabilities.didDelete = object.at("didDelete").get<bool>();
        if(object.contains("willDelete"))
            file_operation_client_capabilities.willDelete = object.at("willDelete").get<bool>();
    }

    auto to_json(nlohmann::json& object, const FileOperationClientCapabilities&
    file_operation_client_capabilities) noexcept -> void
    {
        if(file_operation_client_capabilities.dynamicRegistration.has_value())
            object["dynamicRegistration"] = *file_operation_client_capabilities.dynamicRegistration
            ;
        if(file_operation_client_capabilities.didCreate.has_value())
            object["didCreate"] = *file_operation_client_capabilities.didCreate;
        if(file_operation_client_capabilities.willCreate.has_value())
            object["willCreate"] = *file_operation_client_capabilities.willCreate;
        if(file_operation_client_capabilities.didRename.has_value())
            object["didRename"] = *file_operation_client_capabilities.didRename;
        if(file_operation_client_capabilities.willRename.has_value())
            object["willRename"] = *file_operation_client_capabilities.willRename;
        if(file_operation_client_capabilities.didDelete.has_value())
            object["didDelete"] = *file_operation_client_capabilities.didDelete;
        if(file_operation_client_capabilities.willDelete.has_value())
            object["willDelete"] = *file_operation_client_capabilities.willDelete;
    }
}

#endif