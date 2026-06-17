// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_diagnostic
#define lyrix_header_guard_eura_diagnostic
#include "Eura/MarkupContent.hpp"
#include "Eura/DiagnosticTag.hpp"
#include "Eura/CodeDescription.hpp"
#include "Eura/DiagnosticSeverity.hpp"
#include "Eura/DiagnosticRelatedInformation.hpp"

namespace Eura
{
    struct [[nodiscard]] Diagnostic final
    {
        Range range;

        std::optional<DiagnosticSeverity> severity;

        std::optional<std::variant<Json::Integer, Json::String>> code;

        std::optional<CodeDescription> codeDescription;

        std::optional<Json::String> source;

        std::variant<Json::String, MarkupContent> message;

        std::optional<std::vector<DiagnosticTag>> tags;
        
        std::optional<std::vector<DiagnosticRelatedInformation>> relatedInformation;

        std::optional<Json::Any> data;
    };

    auto Deserialize(const Json::Object& object, Diagnostic& diagnostic) noexcept -> void;

    auto Serialize(Json::Object& object, const Diagnostic& diagnostic) noexcept -> void;
}

#endif
#endif