// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_signature_help_options
#define lyrix_header_guard_eura_signature_help_options
#include "Eura/WorkDoneProgressOptions.hpp"

namespace Eura
{
    struct [[nodiscard]] SignatureHelpOptions final : WorkDoneProgressOptions
    {
        std::optional<std::vector<std::string>> triggerCharacters, retriggerCharacters;
    };

    auto from_json(const nlohmann::json& object, SignatureHelpOptions& signature_help_options)
    noexcept -> void;

    auto to_json(nlohmann::json& object, const SignatureHelpOptions& signature_help_options)
    noexcept -> void;
}

#endif
#endif