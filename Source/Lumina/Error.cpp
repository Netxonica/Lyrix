// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Lumina/Error.hpp"

namespace Lumina
{
    Error::Error(const std::size_t code) noexcept : m_code(code){}

    [[nodiscard]] auto Error::code() const noexcept -> std::size_t
    {
        return m_code;
    }
}

#endif