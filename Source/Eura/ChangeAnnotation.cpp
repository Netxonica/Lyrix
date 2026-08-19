// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ChangeAnnotation.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ChangeAnnotation& change_annotation) noexcept ->
    void
    {
        change_annotation.label = object.at("label").get<std::string>();
        if(object.contains("needsConfirmation"))
            change_annotation.needsConfirmation = object.at("needsConfirmation").get<bool>();
        if(object.contains("description"))
            change_annotation.description = object.at("description").get<std::string>();
    }

    auto to_json(nlohmann::json& object, const ChangeAnnotation& change_annotation) noexcept ->
    void
    {
        object["label"] = change_annotation.label;
        if(change_annotation.needsConfirmation.has_value())
            object["needsConfirmation"] = *change_annotation.needsConfirmation;
        if(change_annotation.description.has_value())
            object["description"] = *change_annotation.description;
    }
}

#endif