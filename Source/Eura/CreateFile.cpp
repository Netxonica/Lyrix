// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CreateFile.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, CreateFile& create_file) noexcept -> void
    {
        create_file.kind = object.at("kind").get<std::string>();
        create_file.uri = object.at("uri").get<DocumentUri>();
        if(object.contains("options"))
            create_file.options = object.at("options").get<CreateFileOptions>();
        if(object.contains("annotationId"))
            create_file.annotationId = object.at("annotationId").get<ChangeAnnotationIdentifier>();
    }

    auto to_json(nlohmann::json& object, const CreateFile& create_file) noexcept -> void
    {
        object["kind"] = create_file.kind;
        object["uri"] = create_file.uri;
        if(create_file.options.has_value())
            object["options"] = *create_file.options;
        if(create_file.annotationId.has_value())
            object["annotationId"] = *create_file.annotationId;
    }
}

#endif