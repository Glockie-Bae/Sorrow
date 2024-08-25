workspace "Sorrow"
	architecture"x64"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Sorrow/vendor/GLFW/include"
IncludeDir["Glad"] = "Sorrow/vendor/Glad/include"
IncludeDir["ImGui"] = "Sorrow/vendor/imgui"

include "Sorrow/vendor/GLFW"
include "Sorrow/vendor/Glad"
include "Sorrow/vendor/imgui"

project "Sorrow"
	location "Sorrow"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "swpch.h"
	pchsource "Sorrow/src/swpch.cpp"
	
	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links {
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
	

	defines{
	"SORROW_PLATFORM_WINDOWS",
	"SORROW_BUILD_DLL",
	"GLFW_INCLUDE_NONE"

	}

	postbuildcommands{
		("{COPYDIR} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
	}

	filter"configurations:Debug"
	    defines "SW_DEBUG"
		buildoptions "/MDd"
	    symbols "On"

    filter"configurations:Release"
	    defines "SW_RELEASE"
		buildoptions "/MD"
	    optimize "On"

	filter"configurations:Dist"
	    defines "SW_DIST"
		buildoptions "/MD"
	    optimize "On"


project "Sandbox"
    location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"Sorrow/vendor/spdlog/include",
		"Sorrow/src"
	}

	links{
		"Sorrow"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
	

	    defines{
	    "SORROW_PLATFORM_WINDOWS",
	    }


	filter"configurations:Debug"
	    defines "SW_DEBUG"
		buildoptions "/MDd"
	    symbols "On"

    filter"configurations:Release"
	    defines "SW_RELEASE"
		buildoptions "/MD"
	    optimize "On"

	filter"configurations:Dist"
	    defines "SW_DIST"
		buildoptions "/MD"
	    optimize "On"