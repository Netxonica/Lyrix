// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Client.hpp"
#include <iostream>

namespace Eura
{
    auto Client(std::mutex& mutex, const std::string message) noexcept -> void
    {
        std::string content = "Content-Length: ";
        content += std::to_string(message.size());
        content += "\r\n\r\n";
        content += message;
        std::lock_guard<std::mutex> locked{mutex};
        std::cout << message << std::flush;
    }
}

#endif