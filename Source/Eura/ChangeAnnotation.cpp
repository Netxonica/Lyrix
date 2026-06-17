// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ChangeAnnotation.hpp"

namespace Eura
{
    auto Deserialize(const Json::Object& object, ChangeAnnotation& change_annotation) noexcept ->
    void
    {
        change_annotation.label = object.Retrieve("label").As<Json::String>();
        if(object.Contains("needsConfirmation"))
            change_annotation.needsConfirmation = object.Retrieve("needsConfirmation").As<Json::
            Boolean>();
        if(object.Contains("description"))
            change_annotation.description = object.Retrieve("description").As<Json::String>();
    }

    auto Serialize(Json::Object& object, const ChangeAnnotation& change_annotation) noexcept ->
    void
    {
        object.fields.emplace_back("label", change_annotation.label);
        if(change_annotation.needsConfirmation.has_value())
            object.fields.emplace_back("needsConfirmation", *change_annotation.needsConfirmation);
        if(change_annotation.description.has_value())
            object.fields.emplace_back("description", *change_annotation.description);
    }
}

#endif