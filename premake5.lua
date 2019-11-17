workspace "SG-Engine"
	architecture "x64"
	configurations {"Debug", "Release", "Distribute"}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
IncludeDir = {}
IncludeDir["GLFW"] = "SG-Engine/thirdparty/GLFW/include"

include "SG-Engine/thirdparty/GLFW"

project "Playground"
	location "Playground"
	kind "ConsoleApp"
	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	includedirs{
		"SG-Engine/thirdparty/spdlog/spdlog-include",
		"SG-Engine/src",
		"SG-Engine/src/SGEngine/"

	}
	links "SG-Engine"

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		defines "SGE_PLATFORM_WINDOWS"

	filter "configurations:Debug"
		defines "SGE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SGE_RELEASE"
		optimize "On"

	filter "configurations:Distribute"
		defines "SGE_DISTRIBUTE"
		optimize "On"

	dependson "SG-Engine"

project "SG-Engine"
	location "SG-Engine"
	kind "SharedLib"
	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "sgepch.h"
	pchsource "SG-Engine/src/sgepch.cpp"

	files	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	includedirs{
		"%{prj.name}/thirdparty/spdlog/spdlog-include",
		"%{prj.name}/src/",
		"%{prj.name}/src/SGEngine/",
		"%{IncludeDir.GLFW}"
	}

	links{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines { "SGE_PLATFORM_WINDOWS","SGE_BUILD_DLL" }
		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir.. "/Playground")
		}
	filter "configurations:Debug"
		defines "SGE_DEBUG"
		symbols "On"
	filter "configurations:Release"
		defines "SGE_RELEASE"
		optimize "On"
	filter "configurations:Distribute"
		defines "SGE_DISTRIBUTE"
		optimize "On"

