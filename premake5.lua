workspace "Skeleton"
    architecture "x32"
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
            "sfml-graphics-s-d",
            "sfml-window-s-d",
            "sfml-audio-s-d",
            "sfml-system-s-d"
        }

    filter "configurations:Release"
        defines {"NDEBUG"}
        optimize "On"
        links {
            "sfml-graphics-s",
            "sfml-window-s",
            "sfml-audio-s",
            "sfml-system-s"
        }

    filter "configurations:*"
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

    postbuildcommands { "{COPY} ../".._OPTIONS["sfmlpath"].."/bin/openal32.dll ../bin/"..outputdir.."/%{prj.name}/" }

    filter "configurations:Debug"
        defines {"DEBUG"}
        symbols "On"
        links {
            "sfml-graphics-s-d",
            "sfml-window-s-d",
            "sfml-audio-s-d",
            "sfml-system-s-d"
        }

    filter "configurations:Release"
        defines {"NDEBUG"}
        optimize "On"
        links {
            "sfml-graphics-s",
            "sfml-window-s",
            "sfml-audio-s",
            "sfml-system-s"
        }
    
    filter "configurations:*"
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
