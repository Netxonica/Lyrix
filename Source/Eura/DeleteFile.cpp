// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DeleteFile.hpp"

namespace Eura
{
    auto Deserialize(const Json::Object& object, DeleteFile& delete_file) noexcept -> void
    {
        delete_file.kind = object.Retrieve("kind").As<Json::String>();
        delete_file.uri = object.Retrieve("uri").As<DocumentUri>();
        if(object.Contains("options"))
        {
            DeleteFileOptions options;
            Deserialize(object.Retrieve("options").As<Json::Object>(), options);
            delete_file.options = options;
        }
        if(object.Contains("annotationId"))
            delete_file.annotationId = object.Retrieve("annotationId").As<
            ChangeAnnotationIdentifier>();
    }

    auto Serialize(Json::Object& object, const DeleteFile& delete_file) noexcept -> void
    {
        object.fields.emplace_back("kind", delete_file.kind);
        object.fields.emplace_back("uri", delete_file.uri);
        if(delete_file.options.has_value())
            Serialize(object.NestedObject("options"), *delete_file.options);
        if(delete_file.annotationId.has_value())
            object.fields.emplace_back("annotationId", *delete_file.annotationId);
    }
}

#endif