// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Token.hpp"

namespace Eura::Json
{
    Token::Token(const Type type) noexcept : m_type(type){}

    Token::Token(const Type type, const std::size_t index) noexcept : m_type(type), m_index(index){
    }

    [[nodiscard]] auto Token::Get() const noexcept -> Type
    {
        return m_type;
    }

    [[nodiscard]] auto Token::Get(const Slices& slices) const noexcept -> String
    {
        return slices[m_index];
    }

    [[nodiscard]] auto Token::Get(const Strings& strings) const noexcept -> String
    {
        return strings[m_index];
    }
}

#endif