// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/RenameFile.hpp"

namespace Eura
{
    auto Deserialize(const Json::Object& object, RenameFile& rename_file) noexcept -> void
    {
        rename_file.kind = object.Retrieve("kind").As<Json::String>();
        rename_file.oldUri = object.Retrieve("oldUri").As<Json::String>();
        rename_file.newUri = object.Retrieve("newUri").As<Json::String>();
        if(object.Contains("options"))
        {
            RenameFileOptions options;
            Deserialize(object.Retrieve("options").As<Json::Object>(), options);
            rename_file.options = options;
        }
        if(object.Contains("annotationId"))
            rename_file.annotationId = object.Retrieve("annotationId").As<
            ChangeAnnotationIdentifier>();
    }

    auto Serialize(Json::Object& object, const RenameFile& rename_file) noexcept -> void
    {
        object.fields.emplace_back("kind", rename_file.kind);
        object.fields.emplace_back("oldUri", rename_file.oldUri);
        object.fields.emplace_back("newUri", rename_file.newUri);
        if(rename_file.options.has_value())
            Serialize(object.NestedObject("options"), *rename_file.options);
        if(rename_file.annotationId.has_value())
            object.fields.emplace_back("annotationId", *rename_file.annotationId);
    }
}

#endif