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

        std::optional<std::variant<std::int32_t, std::string>> code;

        std::optional<CodeDescription> codeDescription;

        std::optional<std::string> source;

        std::variant<std::string, MarkupContent> message;

        std::optional<std::vector<DiagnosticTag>> tags;

        std::optional<std::vector<DiagnosticRelatedInformation>> relatedInformation;

        std::optional<nlohmann::json> data;
    };

    auto from_json(const nlohmann::json& object, Diagnostic& diagnostic) noexcept -> void;

    auto to_json(nlohmann::json& object, const Diagnostic& diagnostic) noexcept -> void;
}

#endif
#endif