workspace "Skeleton"
    defines {"SFML_STATIC"}

    configurations {
        "Debug",
        "Release"
    }

    cppdialect "C++17"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Skeleton"
    location "Skeleton"
    kind "StaticLib"
    language "C++"

    targetdir ("bin/"..outputdir.."/%{prj.name}")
    objdir ("bin-int/"..outputdir.."/%{prj.name}")
    
    includedirs "vendor/SFML_VS/include"
    libdirs {"vendor/SFML_VS/lib"}
    -- staticruntime "on"

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

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

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    -- staticruntime "on"

    targetdir ("bin/"..outputdir.."/%{prj.name}")
    objdir ("bin-int/"..outputdir.."/%{prj.name}")

    includedirs {
        "Skeleton/src",
        "vendor/SFML_VS/include"
    }

    links {"Skeleton"}

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    filter "configurations:Debug"
        defines {"DEBUG"}
        symbols "On"

    filter "configurations:Release"
        defines {"NDEBUG"}
        optimize "On"