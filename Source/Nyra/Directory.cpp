// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Nyra/Directory.hpp"
#include <filesystem>

namespace Nyra::Directory
{
    [[nodiscard]] auto Exists(const std::string_view path) noexcept -> bool
    {
        return std::filesystem::is_directory(path);
    }

    [[nodiscard]] auto Create(const std::string_view path) noexcept -> bool
    {
        return std::filesystem::create_directory(path);
    }
}

#endif