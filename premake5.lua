workspace "Cazel"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Cazel"
	location "Cazel"
	kind "SharedLib"
	language "C++"

	targetdir("bin/" .. outputdir .."/%{prj.name}")
	objdir("bin-int/" .. outputdir .."/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"

	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.26100.0"

		defines
		{
			"CZ_PLATFORM_WINDOWS",
			"CZ_BUILD_DLL"
		}

		buildoptions {"/utf-8"}


	filter "configurations:Debug"
		defines "HZ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "HZ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "HZ_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir("bin/" .. outputdir .."/%{prj.name}")
	objdir("bin-int/" .. outputdir .."/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Cazel/vendor/spdlog/include",
		"Cazel/src"
	}

	links
	{
		"Cazel"
	}


	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.26100.0"

		defines
		{
			"CZ_PLATFORM_WINDOWS"
		}

		postbuildcommands
		{
			("{COPYFILE} %{wks.location}bin/" .. outputdir .. "/Cazel/Cazel.dll %{wks.location}bin/" .. outputdir .. "/%{prj.name}/")
		}

		buildoptions {"/utf-8"}


	filter "configurations:Debug"
		defines "HZ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "HZ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "HZ_DIST"
		optimize "On"