// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Nyra/Identifier.hpp"
#include "Nyra/CharacterSets.hpp"

namespace Nyra
{
    [[nodiscard]] auto Identifier(const std::string_view content) noexcept -> bool
    {
        bool first = true;
        for(const char character : content)
        {
            if(first)
                switch(character)
                {
                    default:
                        return false;
                    case '_':
                    case $lyrix_alpha:
                        first = false;
                }
            else
                switch(character)
                {
                    default:
                        return false;
                    case '_':
                    case $lyrix_alphanumeric:
                    break;
                }
        }
        return true;
    }
}

#endif