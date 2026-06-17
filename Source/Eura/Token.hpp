// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_token
#define lyrix_header_guard_eura_token
#include "Eura/Type.hpp"
#include "Eura/String.hpp"
#include "Eura/Slices.hpp"
#include "Eura/Strings.hpp"

namespace Eura::Json
{
    class [[nodiscard]] Token final
    {
        Type m_type;

        std::size_t m_index;
    public:
        explicit Token(const Type type) noexcept;

        explicit Token(const Type type, const std::size_t index) noexcept;

        [[nodiscard]] auto Get() const noexcept -> Type;

        [[nodiscard]] auto Get(const Slices& slices) const noexcept -> String;

        [[nodiscard]] auto Get(const Strings& strings) const noexcept -> String;
    };
}

#endif
#endif