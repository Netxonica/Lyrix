// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DiagnosticRelatedInformation.hpp"

namespace Eura
{
    auto Deserialize(const Json::Object& object, DiagnosticRelatedInformation&
    diagnostic_related_information) noexcept -> void
    {
        Deserialize(object.Retrieve("location").As<Json::Object>(), diagnostic_related_information.
        location);
        diagnostic_related_information.message = object.Retrieve("message").As<Json::String>();
    }

    auto Serialize(Json::Object& object, const DiagnosticRelatedInformation&
    diagnostic_related_information) noexcept -> void
    {
        Serialize(object.NestedObject("location"), diagnostic_related_information.location);
        object.fields.emplace_back("message", diagnostic_related_information.message);
    }
}

#endif