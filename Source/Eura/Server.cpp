// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Server.hpp"
#include <cstdlib>

namespace Eura
{
    [[noreturn]] auto Listen() noexcept -> void
    {
        std::exit(0);
    }
}

#endif