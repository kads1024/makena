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
	
project "Makena"
	location "Makena"
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
		"%{prj.name}/vendor/spdlog/include"	
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"MKN_PLATFORM_WINDOWS",
			"MKN_BUILD_DLL"
		}
		
		postbuildcommands 
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
	
	filter "configurations:Debug"
		defines "MKN_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "MKN_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "MKN_DIST"
		optimize "On"
		
project "Sandbox"
	location "Sandbox"
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
		"Makena/vendor/spdlog/include",
		"Makena/src"
	}
	
	links
	{
		"Makena"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"MKN_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "MKN_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "MKN_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "MKN_DIST"
		optimize "On"