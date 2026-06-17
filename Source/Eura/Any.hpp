// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_any
#define lyrix_header_guard_eura_any
#include <cstdlib>
#include <variant>
#include <optional>
#include "Eura/Null.hpp"
#include "Eura/Object.hpp"
#include "Eura/Boolean.hpp"
#include "Eura/Integer.hpp"
#include "Eura/Decimal.hpp"
#include "Eura/Uinteger.hpp"

namespace Eura::Json
{
    struct [[nodiscard]] Any final : public std::variant<Null, Boolean, Uinteger, Integer, Decimal,
    String, Object, Array>
    {
        using Underlying = std::variant<Null, Boolean, Uinteger, Integer, Decimal, String, Object,
        Array>;

        using Underlying::Underlying;

        template<class T> [[nodiscard]] auto As() noexcept -> T&
        {
            return std::get<T>(*this);
        }

        template<class T> [[nodiscard]] auto As() const noexcept -> const T&
        {
            return std::get<T>(*this);
        }

        [[nodiscard]] auto IsNull() const noexcept -> bool;

        [[nodiscard]] auto IsBoolean() const noexcept -> bool;

        [[nodiscard]] auto IsUinteger() const noexcept -> bool;

        [[nodiscard]] auto IsInteger() const noexcept -> bool;

        [[nodiscard]] auto IsDecimal() const noexcept -> bool;

        [[nodiscard]] auto IsString() const noexcept -> bool;

        [[nodiscard]] auto IsObject() const noexcept -> bool;

        [[nodiscard]] auto IsArray() const noexcept -> bool;
    };
}

#endif
#endif