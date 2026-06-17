// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Nyra/Create.hpp"
#include <print>
#include <thread>
#include <memory>
#include "Nyra/File.hpp"
#include "Nyra/Error.hpp"
#include "Lumina/Style.hpp"
#include "Nyra/Symlink.hpp"
#include "Nyra/Directory.hpp"

namespace Nyra
{
    auto Create(const std::string_view name) noexcept -> void
    {
        std::string path{name};
        path += ".orion/";
        const unsigned int jobs = std::thread::hardware_concurrency();
        if(jobs == 0)
            std::make_unique<Error>(15uz)->Report();
        else if(Symlink::Check(path) or Directory::Exists(path))
            std::make_unique<Error>(16uz, name, path)->Report();
        else if(not Directory::Create(path))
            std::make_unique<Error>(17uz, name, path)->Report();
        else if(not File::Write(path + std::string(name) + ".elyra", "jobs = " + std::to_string(jobs) + ";"))
            std::make_unique<Error>(18uz, name, path + std::string(name) + ".elyra")->Report();
        else
            std::println(stdout, "the project {}{}{} was successfully created", Lumina::Style::Data
            , name, Lumina::Style::Normal);
    }
}

#endif