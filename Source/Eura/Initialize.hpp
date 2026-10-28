// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_initialize
#define lyrix_header_guard_eura_initialize
#include <mutex>
#include <atomic>
#include "Eura/RequestMessage.hpp"

namespace Eura
{
    enum class [[nodiscard]] Initialization : std::uint8_t
    {
        Uninitialized = 0u,
        Initializing = 1u,
        Initialized = 2u
    };

    auto Initialize(std::mutex& mutex, const RequestMessage& request_message, std::atomic<
    Initialization>& initialization) noexcept -> void;
}

#endif
#endif