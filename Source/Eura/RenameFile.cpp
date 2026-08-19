// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/RenameFile.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, RenameFile& rename_file) noexcept -> void
    {
        rename_file.kind = object.at("kind").get<std::string>();
        rename_file.oldUri = object.at("oldUri").get<DocumentUri>();
        rename_file.newUri = object.at("newUri").get<DocumentUri>();
        if(object.contains("options"))
            rename_file.options = object.at("options").get<RenameFileOptions>();
        if(object.contains("annotationId"))
            rename_file.annotationId = object.at("annotationId").get<ChangeAnnotationIdentifier>();
    }

    auto to_json(nlohmann::json& object, const RenameFile& rename_file) noexcept -> void
    {
        object["kind"] = rename_file.kind;
        object["oldUri"] = rename_file.oldUri;
        object["newUri"] = rename_file.newUri;
        if(rename_file.options.has_value())
            object["options"] = *rename_file.options;
        if(rename_file.annotationId.has_value())
            object["annotationId"] = *rename_file.annotationId;
    }
}

#endif