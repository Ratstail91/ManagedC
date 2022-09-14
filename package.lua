package("managedc")
    set_kind("library", { headeronly = true })
    set_description("Reference counter garabage collection for C")

    add_urls("https://github.com/Frityet/ManagedC.git")
    add_versions("1.0.0", "350800021f8d41e5717e76f8dfb0485d45781996")
    add_versions("1.1.0", "878158a7f185aaaa38b8855afd91f89b05c9df13")
    add_versions("1.1.1", "eb70de26ca4cc724efd14dc50ec9bc990ec92271")
    add_versions("1.1.2", "0068462307a1901a1b30410ae53721ca7e88cb10")
    add_versions("1.2.0", "65dadb723a557b1e295b2890e2eeac2c0e865880")
    add_versions("1.2.1", "6c46b8b9764cabf7cf9c0a49e6ee7aa35039f4c1")
    add_versions("1.3.0", "cc900aea02c39e6d5ee7dc38f1b14c3959eca008")
    add_versions("1.3.1", "0b14ab3c61682963c71613a73dad6aeb7dd446ff")
    add_versions("1.4.0", "d5e445d4d1aed726226342b15704cb64ffa667c6")
    add_versions("1.4.1", "19ace17f26460e2a2aa6969414b499c2a8f2964d")
    add_versions("1.4.2", "b12303b3d5d26097554efbd05930b47030fe4711")
    add_versions("1.5.0", "f4cce9c1aee952d603c18b73dc6219ea15b91717")
    add_versions("2.0.0-beta", "6963abbe67fccce834e4cc1c5d3ecdb73a55701f")
    add_versions("2.1.0-beta", "1217d7f55ee04f2b692e998e451b5a6b000f4618")
    add_versions("2.2.1-beta", "ca8f6af418e3d4713cb902128232c15e2dafb071")
    add_versions("2.3.0", "6a4f91f2b839fc26995008b42bcefe3a4b54ef27")

    on_install(function (package)
        os.cp("**.h", package:installdir("include"), {
            rootdir = "src/"
        })
    end)

    on_test(function (package)
         assert(package:has_cfuncs("managed_allocate", { includes = "managed.h" }))
         assert(package:has_cfuncs("managed_string", { includes = "managed/mstring.h" }))
    end)
