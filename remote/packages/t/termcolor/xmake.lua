package("termcolor")
    set_kind("library", {headeronly = true})
    set_description("A library that supports setting color flags to print colorful character")

    add_urls("https://github.com/ACoderOrHacker/ox.termcolor.git")
    add_versions("0.1.0", "ac1f5c932bf5930eaa4346e0a390833da0de9015")

    on_install(function (package)
        local configs = {}
        if package:config("shared") then
            configs.kind = "shared"
        end
        import("package.tools.xmake").install(package, configs)
    end)

    on_test(function (package)
        -- TODO check includes and interfaces
        -- assert(package:has_cfuncs("foo", {includes = "foo.h"})
    end)
