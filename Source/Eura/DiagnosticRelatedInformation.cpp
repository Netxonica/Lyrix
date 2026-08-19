// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DiagnosticRelatedInformation.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DiagnosticRelatedInformation&
    diagnostic_related_information) noexcept -> void
    {
        diagnostic_related_information.location = object.at("location").get<Location>();
        diagnostic_related_information.message = object.at("message").get<std::string>();
    }

    auto to_json(nlohmann::json& object, const DiagnosticRelatedInformation&
    diagnostic_related_information) noexcept -> void
    {
        object["location"] = diagnostic_related_information.location;
        object["message"] = diagnostic_related_information.message;
    }
}

#endif