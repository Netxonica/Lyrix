// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Nyra/Symlink.hpp"
#include <filesystem>

namespace Nyra::Symlink
{
    [[nodiscard]] auto Check(const std::string_view path) noexcept -> bool
    {
        return std::filesystem::is_symlink(path);
    }
}

#endif