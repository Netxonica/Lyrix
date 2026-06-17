// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Any.hpp"

namespace Eura::Json
{
    [[nodiscard]] auto Any::IsNull() const noexcept -> bool
    {
        return std::holds_alternative<Null>(*this);
    }

    [[nodiscard]] auto Any::IsBoolean() const noexcept -> bool
    {
        return std::holds_alternative<Boolean>(*this);
    }

    [[nodiscard]] auto Any::IsUinteger() const noexcept -> bool
    {
        return std::holds_alternative<Uinteger>(*this);
    }

    [[nodiscard]] auto Any::IsInteger() const noexcept -> bool
    {
        return std::holds_alternative<Integer>(*this);
    }

    [[nodiscard]] auto Any::IsDecimal() const noexcept -> bool
    {
        return std::holds_alternative<Decimal>(*this);
    }

    [[nodiscard]] auto Any::IsString() const noexcept -> bool
    {
        return std::holds_alternative<String>(*this);
    }

    [[nodiscard]] auto Any::IsObject() const noexcept -> bool
    {
        return std::holds_alternative<Object>(*this);
    }

    [[nodiscard]] auto Any::IsArray() const noexcept -> bool
    {
        return std::holds_alternative<Array>(*this);
    }
}

#endif