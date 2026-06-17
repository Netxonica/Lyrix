// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_diagnostic_related_information
#define lyrix_header_guard_eura_diagnostic_related_information
#include "Eura/Location.hpp"

namespace Eura
{
    struct [[nodiscard]] DiagnosticRelatedInformation final
    {
        Location location;

        Json::String message;
    };

    auto Deserialize(const Json::Object& object, DiagnosticRelatedInformation&
    diagnostic_related_information) noexcept -> void;

    auto Serialize(Json::Object& object, const DiagnosticRelatedInformation&
    diagnostic_related_information) noexcept -> void;
}

#endif
#endif