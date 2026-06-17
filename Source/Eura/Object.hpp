// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_object
#define lyrix_header_guard_eura_object
#include <utility>
#include "Eura/Array.hpp"
#include "Eura/String.hpp"

namespace Eura::Json
{
    struct [[nodiscard]] Object final
    {
        std::vector<std::pair<String, Any>> fields;

        [[nodiscard]] auto Contains(const std::string_view name) const noexcept -> bool;

        [[nodiscard]] auto Retrieve(const std::string_view name) noexcept -> Any&;

        [[nodiscard]] auto Retrieve(const std::string_view name) const noexcept -> const Any&;

        [[nodiscard]] auto NestedObject(const std::string_view name) noexcept -> Object&;

        [[nodiscard]] auto NestedArray(const std::string_view name) noexcept -> Array&;
    };
}

#endif
#endif