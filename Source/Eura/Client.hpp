// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_client
#define lyrix_header_guard_eura_client
#include <mutex>
#include <string>

namespace Eura
{
    auto Client(std::mutex& mutex, const std::string message) noexcept -> void;
}

#endif
#endif