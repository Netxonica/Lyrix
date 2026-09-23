// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_moniker
#define lyrix_header_guard_eura_moniker
#include "Eura/Json.hpp"
#include "Eura/MonikerKind.hpp"
#include "Eura/UniquenessLevel.hpp"

namespace Eura
{
    struct [[nodiscard]] Moniker final
    {
        std::string scheme, identifier;

        UniquenessLevel unique;

        std::optional<MonikerKind> kind;
    };

    auto from_json(const nlohmann::json& object, Moniker& moniker) noexcept -> void;

    auto to_json(nlohmann::json& object, const Moniker& moniker) noexcept -> void;
}

#endif
#endif