// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Nyra/File.hpp"
#include <memory>
#include <fstream>
#include <filesystem>
#include "Nyra/Error.hpp"
#include "Lumina/Style.hpp"

namespace Nyra::File
{
    [[nodiscard]] auto Write(const std::string_view path, const std::string_view content) noexcept
    -> bool
    {
        std::ofstream stream{path.data(), std::ios::out bitor std::ios::binary};
        if(not stream.is_open())
            return false;
        stream << content;
        if(not stream.good())
            return false;
        stream.flush();
        if(not stream.good())
            return false;
        stream.close();
        return stream.good();
    }

    [[nodiscard]] auto Exists(const std::string_view path) noexcept -> bool
    {
        return std::filesystem::is_regular_file(path);
    }

    [[nodiscard]] auto Read(const std::string_view path) noexcept -> std::optional<std::string>
    {
        const std::size_t size = std::filesystem::file_size(path);
        std::string content;
        bool result = false;
        content.resize_and_overwrite(size, [path, &result](char* data, const std::size_t size)
        noexcept
        {
            std::ifstream stream(path.data(), std::ios_base::binary);
            if(not stream.is_open() or stream.fail())
            {
                result = true;
                return size;
            }
            stream.read(data, static_cast<std::streamsize>(size));
            if(not stream or stream.bad())
                result = true;
            return size;
        });
        if(result)
        {
            std::make_unique<Error>(11uz, path)->Report();
            return std::nullopt;
        }
        return content;
    }
}

#endif