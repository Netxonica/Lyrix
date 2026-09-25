// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_signature_information
#define lyrix_header_guard_eura_signature_information
#include "Eura/ParameterInformation.hpp"

namespace Eura
{
    struct [[nodiscard]] SignatureInformation final
    {
        std::string label;

        std::optional<std::variant<std::string, MarkupContent>> documentation;

        std::optional<std::vector<ParameterInformation>> parameters;

        std::optional<std::variant<std::uint32_t, std::nullptr_t>> activeParameter;
    };

    auto from_json(const nlohmann::json& object, SignatureInformation& signature_information)
    noexcept -> void;

    auto to_json(nlohmann::json& object, const SignatureInformation& signature_information)
    noexcept -> void;
}

#endif
#endif