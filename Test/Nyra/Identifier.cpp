// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Nyra/Identifier.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    return Nyra::Identifier("name") and Nyra::Identifier("Name") and Nyra::Identifier("_name") and
    Nyra::Identifier("_Name") and Nyra::Identifier("name4267") and Nyra::Identifier("_name4267")
    and Nyra::Identifier("Name4267") and Nyra::Identifier("_Name4267") and not Nyra::Identifier("@"
    ) and not Nyra::Identifier("4267") and not Nyra::Identifier(" ") and not Nyra::Identifier(
    "@name");
}

int main()
{
    return not lyrix_test();
}

#endif