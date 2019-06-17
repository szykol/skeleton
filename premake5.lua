workspace "Skeleton"
    architecture "x64"
    defines {"SFML_STATIC"}

    configurations {
        "Debug",
        "Release"
    }

    cppdialect "C++17"

    newoption {
        trigger     = "sfmlpath",
        value       = "path",
        description = "Path to the SFML root directory (must be relative to this file's location)"
     }

    if not _OPTIONS["sfmlpath"] then
        _OPTIONS["sfmlpath"] = "vendor/SFML"
    end

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

if os.host() == "windows" then
    debugSFMLlibs = {
        "sfml-graphics-s-d",
        "sfml-window-s-d",
        "sfml-audio-s-d",
        "sfml-system-s-d"
    }

    releaseSFMLlibs = {
        "sfml-graphics-s",
        "sfml-window-s",
        "sfml-audio-s",
        "sfml-system-s"
    }
end
if os.host() == "linux" then
    debugSFMLlibs = {
        "sfml-graphics",
        "sfml-window",
        "sfml-audio",
        "sfml-system"
    }
    
    releaseSFMLlibs = debugSFMLlibs
end

project "Skeleton"
    location "Skeleton"
    kind "StaticLib"
    language "C++"

    targetdir ("bin/"..outputdir.."/%{prj.name}")
    objdir ("bin-int/"..outputdir.."/%{prj.name}")
    
    includedirs (_OPTIONS["sfmlpath"].."/include")
    libdirs (_OPTIONS["sfmlpath"].."/lib")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        defines {"DEBUG"}
        symbols "On"
        links {
            debugSFMLlibs
        }

    filter "configurations:Release"
        defines {"NDEBUG"}
        optimize "On"
        links {
            releaseSFMLlibs
        }

    filter {"configurations:*", "system:windows"}
        links {
			"opengl32",
			"freetype",
			"winmm",
			"gdi32",
			"flac",
			"vorbisenc",
			"vorbisfile",
			"vorbis",
			"ogg",
            "ws2_32",
            "openal32"
        }

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/"..outputdir.."/%{prj.name}")
    objdir ("bin-int/"..outputdir.."/%{prj.name}")

    includedirs {
        "Skeleton/src",
        _OPTIONS["sfmlpath"].."/include"
    }

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }
    
    links {"Skeleton"}
    libdirs {_OPTIONS["sfmlpath"].."/lib"}


    filter "configurations:Debug"
        defines {"DEBUG"}
        symbols "On"
        links {
            debugSFMLlibs
        }

    filter "configurations:Release"
        defines {"NDEBUG"}
        optimize "On"
        links {
            releaseSFMLlibs
        }
    
    filter {"configurations:*", "system:windows"}
        links {
            "opengl32",
            "freetype",
            "winmm",
            "gdi32",
            "flac",
            "vorbisenc",
            "vorbisfile",
            "vorbis",
            "ogg",
            "ws2_32",
            "openal32",
        }

        postbuildcommands { "{COPY} ../".._OPTIONS["sfmlpath"].."/bin/openal32.dll ../bin/"..outputdir.."/%{prj.name}/" }

