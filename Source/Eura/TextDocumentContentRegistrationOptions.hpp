// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_text_document_content_registration_options
#define lyrix_header_guard_eura_text_document_content_registration_options
#include "Eura/StaticRegistrationOptions.hpp"
#include "Eura/TextDocumentContentOptions.hpp"

namespace Eura
{
    struct [[nodiscard]] TextDocumentContentRegistrationOptions final : TextDocumentContentOptions,
    StaticRegistrationOptions{};

    auto from_json(const nlohmann::json& object, TextDocumentContentRegistrationOptions&
    text_document_content_registration_options) noexcept -> void;

    auto to_json(nlohmann::json& object, const TextDocumentContentRegistrationOptions&
    text_document_content_registration_options) noexcept -> void;
}

#endif
#endif