// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Elyra/Error.hpp"

namespace Elyra
{
    Error::Error(const std::size_t code) noexcept : Lumina::Error(code){}

    auto Error::operator=(const std::string_view file) noexcept -> void
    {
        m_file = file;
    }

    auto Error::Report() const noexcept -> void
    {
        
    }
}

#endif