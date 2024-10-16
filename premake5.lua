workspace "Makena"
	architecture "x64"
	startproject "Sandbox"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	
-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Makena/vendor/glfw/include"
IncludeDir["Glad"] = "Makena/vendor/Glad/include"
IncludeDir["ImGui"] = "Makena/vendor/imgui"
IncludeDir["glm"] = "Makena/vendor/glm"

group "Dependencies"
	include "Makena/vendor/glfw"
	include "Makena/vendor/Glad"
	include "Makena/vendor/imgui"
group ""

project "Makena"
	location "Makena"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "mknpch.h"
	pchsource "Makena/src/mknpch.cpp"

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}
	
	includedirs 
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}
	
	links
	{
		"GLFW",
		"Glad",
		"opengl32.lib",
		"ImGui"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"
		
		defines
		{
			"MKN_PLATFORM_WINDOWS",
			"MKN_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}
		
		postbuildcommands 
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}
	
	filter "configurations:Debug"
		defines "MKN_DEBUG"
		runtime "Debug"
		symbols "On"
	
	filter "configurations:Release"
		defines "MKN_RELEASE"
		runtime "Release"
		optimize "On"
		
	filter "configurations:Dist"
		defines "MKN_DIST"
		runtime "Release"
		optimize "On"
		
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}
	
	includedirs 
	{
		"Makena/vendor/spdlog/include",
		"Makena/src",
		"%{IncludeDir.glm}"
	}
	
	links
	{
		"Makena"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"
		
		defines
		{
			"MKN_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "MKN_DEBUG"
		runtime "Debug"
		symbols "On"
	
	filter "configurations:Release"
		defines "MKN_RELEASE"
		runtime "Release"
		optimize "On"
		
	filter "configurations:Dist"
		defines "MKN_DIST"
		runtime "Release"
		optimize "On"