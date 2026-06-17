// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Nyra/System.hpp"

namespace Nyra
{
    [[nodiscard]] auto Stringify(const System system) noexcept -> std::string_view
    {
        switch(system)
        {
            using enum System;
            case Darwin:
                return "darwin";
            case Linux:
                return "linux";
            case Windows:
                return "windows";
        }
    }
}

#endif