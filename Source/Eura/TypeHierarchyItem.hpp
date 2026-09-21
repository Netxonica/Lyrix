// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_type_hierarchy_item
#define lyrix_header_guard_eura_type_hierarchy_item
#include "Eura/Range.hpp"
#include "Eura/SymbolTag.hpp"
#include "Eura/SymbolKind.hpp"
#include "Eura/DocumentUri.hpp"

namespace Eura
{
    struct [[nodiscard]] TypeHierarchyItem final
    {
        std::string name;

        SymbolKind kind;

        std::optional<std::vector<SymbolTag>> tags;

        std::optional<std::string> detail;

        DocumentUri uri;

        Range range, selectionRange;

        std::optional<nlohmann::json> data;
    };

    auto from_json(const nlohmann::json& object, TypeHierarchyItem& type_hierarchy_item) noexcept
    -> void;

    auto to_json(nlohmann::json& object, const TypeHierarchyItem& type_hierarchy_item) noexcept ->
    void;
}

#endif
#endif