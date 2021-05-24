workspace "ProjectOszi"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "ProjectOszi/vendor/GLFW/include"
IncludeDir["Glad"] = "ProjectOszi/vendor/Glad/include"
IncludeDir["ImGui"] = "ProjectOszi/vendor/imgui"


include "ProjectOszi/vendor/GLFW"
include "ProjectOszi/vendor/Glad"
include "ProjectOszi/vendor/imgui"

project "ProjectOszi"
	location "ProjectOszi"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "ozpch.h"
	pchsource "ProjectOszi/src/ozpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "off"
		systemversion "latest"

		defines
		{
			"OZ_PLATFORM_WINDOWS",
			"OZ_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Application")
		}

	filter "configurations:Debug"
		defines "OZ_DEBUG"
		symbols "On"
		buildoptions "/MDd"

	filter "configurations:Release"
		defines "OZ_RELEASE"
		optimize "Full"

	filter "configurations:Dist"
		defines "OZ_DIST"
		optimize "On"


project "Application"
	location "Application"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"ProjectOszi/vendor/spdlog/include",
		"ProjectOszi/src"
	}

	links
	{
		"ProjectOszi"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"OZ_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "OZ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "OZ_RELEASE"
		optimize "Full"

	filter "configurations:Dist"
		defines "OZ_DIST"
		optimize "On"