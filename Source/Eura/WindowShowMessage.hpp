// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_window_show_message
#define lyrix_header_guard_eura_window_show_message
#include <mutex>
#include <string>
#include "Eura/MessageType.hpp"

namespace Eura
{
    auto WindowShowMessage(std::mutex& mutex, const MessageType message_type, const std::string
    message) noexcept -> void;
}

#endif
#endif