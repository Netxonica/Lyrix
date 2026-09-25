// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_parameter_information
#define lyrix_header_guard_eura_parameter_information
#include "Eura/MarkupContent.hpp"

namespace Eura
{
    struct [[nodiscard]] ParameterInformation final
    {
        std::variant<std::string, std::array<std::uint32_t, 2uz>> label;

        std::optional<std::variant<std::string, MarkupContent>> documentation;
    };

    auto from_json(const nlohmann::json& object, ParameterInformation& parameter_information)
    noexcept -> void;

    auto to_json(nlohmann::json& object, const ParameterInformation& parameter_information)
    noexcept -> void;
}

#endif
#endif