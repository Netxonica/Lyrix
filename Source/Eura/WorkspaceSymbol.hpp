// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_workspace_symbol
#define lyrix_header_guard_eura_workspace_symbol
#include "Eura/Location.hpp"
#include "Eura/SymbolTag.hpp"
#include "Eura/SymbolKind.hpp"
#include "Eura/LocationUriOnly.hpp"

namespace Eura
{
    struct [[nodiscard]] WorkspaceSymbol final
    {
        std::string name;

        SymbolKind kind;

        std::optional<std::vector<SymbolTag>> tags;
        
        std::optional<std::string> containerName;

        std::variant<Location,  LocationUriOnly> location;

        std::optional<nlohmann::json> data;
    };

    auto from_json(const nlohmann::json& object, WorkspaceSymbol& workspace_symbol) noexcept ->
    void;

    auto to_json(nlohmann::json& object, const WorkspaceSymbol& workspace_symbol) noexcept -> void;
}

#endif
#endif