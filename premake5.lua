workspace "SG-Engine"
	architecture "x64"
	configurations {"Debug", "Release", "Distribute"}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

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
		"SG-Engine/src"
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

	files	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	includedirs{
		"%{prj.name}/thirdparty/spdlog/spdlog-include"
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

