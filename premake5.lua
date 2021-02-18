workspace "ProjectOszi"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "ProjectOszi"
	location "ProjectOszi"
	kind "SharedLib"
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
		"ProjectOszi/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"OZ_PLATFORM_WINDOWS",
			"OZ_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Application")
		}

	filter "configurations:Debug"
		defines "OZ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "OZ_RELEASE"
		optimize "On"

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
		optimize "On"

	filter "configurations:Dist"
		defines "OZ_DIST"
		optimize "On"