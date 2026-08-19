// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DeleteFile.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DeleteFile& delete_file) noexcept -> void
    {
        delete_file.kind = object.at("kind").get<std::string>();
        delete_file.uri = object.at("uri").get<DocumentUri>();
        if(object.contains("options"))
            delete_file.options = object.at("options").get<DeleteFileOptions>();
        if(object.contains("annotationId"))
            delete_file.annotationId = object.at("annotationId").get<ChangeAnnotationIdentifier>();
    }

    auto to_json(nlohmann::json& object, const DeleteFile& delete_file) noexcept -> void
    {
        object["kind"] = delete_file.kind;
        object["uri"] = delete_file.uri;
        if(delete_file.options.has_value())
            object["options"] = *delete_file.options;
        if(delete_file.annotationId.has_value())
            object["annotationId"] = *delete_file.annotationId;
    }
}

#endif