// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CreateFile.hpp"

namespace Eura
{
    auto Deserialize(const Json::Object& object, CreateFile& create_file) noexcept -> void
    {
        create_file.kind = object.Retrieve("kind").As<Json::String>();
        create_file.uri = object.Retrieve("uri").As<Json::String>();
        if(object.Contains("options"))
        {
            CreateFileOptions options;
            Deserialize(object.Retrieve("options").As<Json::Object>(), options);
            create_file.options = options;
        }
        if(object.Contains("annotationId"))
            create_file.annotationId = object.Retrieve("annotationId").As<Json::String>();
    }

    auto Serialize(Json::Object& object, const CreateFile& create_file) noexcept -> void
    {
        object.fields.emplace_back("kind", create_file.kind);
        object.fields.emplace_back("uri", create_file.uri);
        if(create_file.options.has_value())
            Serialize(object.NestedObject("options"), *create_file.options);
        if(create_file.annotationId.has_value())
            object.fields.emplace_back("annotationId", *create_file.annotationId);
    }
}

#endif