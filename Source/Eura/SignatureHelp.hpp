// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_signature_help
#define lyrix_header_guard_eura_signature_help
#include "Eura/SignatureInformation.hpp"

namespace Eura
{
    struct [[nodiscard]] SignatureHelp final
    {
        std::vector<SignatureInformation> signatures;

        std::optional<std::uint32_t> activeSignature;

        std::optional<std::variant<std::uint32_t, std::nullptr_t>> activeParameter;
    };

    auto from_json(const nlohmann::json& object, SignatureHelp& signature_help) noexcept -> void;

    auto to_json(nlohmann::json& object, const SignatureHelp& signature_help) noexcept -> void;
}

#endif
#endif