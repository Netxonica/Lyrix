// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/FileOperationOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, FileOperationOptions& file_operation_options)
    noexcept -> void
    {
        if(object.contains("didCreate"))
            file_operation_options.didCreate = object.at("didCreate").get<
            FileOperationRegistrationOptions>();
        if(object.contains("willCreate"))
            file_operation_options.willCreate = object.at("willCreate").get<
            FileOperationRegistrationOptions>();
        if(object.contains("didRename"))
            file_operation_options.didRename = object.at("didRename").get<
            FileOperationRegistrationOptions>();
        if(object.contains("willRename"))
            file_operation_options.willRename = object.at("willRename").get<
            FileOperationRegistrationOptions>();
        if(object.contains("didDelete"))
            file_operation_options.didDelete = object.at("didDelete").get<
            FileOperationRegistrationOptions>();
        if(object.contains("willDelete"))
            file_operation_options.willDelete = object.at("willDelete").get<
            FileOperationRegistrationOptions>();
    }

    auto to_json(nlohmann::json& object, const FileOperationOptions& file_operation_options)
    noexcept -> void
    {
        if(file_operation_options.didCreate.has_value())
            object["didCreate"] = *file_operation_options.didCreate;
        if(file_operation_options.willCreate.has_value())
            object["willCreate"] = *file_operation_options.willCreate;
        if(file_operation_options.didRename.has_value())
            object["didRename"] = *file_operation_options.didRename;
        if(file_operation_options.willRename.has_value())
            object["willRename"] = *file_operation_options.willRename;
        if(file_operation_options.didDelete.has_value())
            object["didDelete"] = *file_operation_options.didDelete;
        if(file_operation_options.willDelete.has_value())
            object["willDelete"] = *file_operation_options.willDelete;
    }
}

#endif