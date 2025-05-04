workspace "ShoonyaGL"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "ShoonyaGL"
	location "ShoonyaGL"
	kind "SharedLib"
	language "C++"

	targetdir ("ShoonyaGL/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("ShoonyaGL/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/%{prj.name}/src/**.h",
		"%{prj.name}/%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/Vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SGL_PLATFORM_WINDOWS",
			"SGL_BUILD_DLL"
		}

		local dllPath = "%{cfg.buildtarget.relpath}"
		local targetDir = "../Sandbox/bin/" .. outputdir .. "/Sandbox"
		postbuildcommands
		{
			"{MKDIR} " .. targetDir,
			("{COPY} " .. dllPath .. " " .. targetDir)
		}

	filter "configurations:Debug"
		defines "SGL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SGL_RELEASE"
		optimize "On"

	filter "configurations:Debug"
		defines "SGL_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("Sandbox/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("Sandbox/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/%{prj.name}/src/**.h",
		"%{prj.name}/%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"ShoonyaGL/Vendor/spdlog/include",
		--"E:/OpenGL/MyGraphicsEngines/ShoonyaGL/ShoonyaGL/Vendor/spdlog/include",
		"ShoonyaGL/ShoonyaGL/src"
	}

	links
	{
		"ShoonyaGL"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SGL_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "SGL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SGL_RELEASE"
		optimize "On"

	filter "configurations:Debug"
		defines "SGL_DIST"
		optimize "On"