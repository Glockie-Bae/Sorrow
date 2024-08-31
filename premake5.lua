workspace "Sorrow"
	architecture"x64"
	startproject "Sandbox"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

	flags                           --���ñ�����ѡ��
	{
		"MultiProcessorCompile"     --�ദ�������б���
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Sorrow/vendor/GLFW/include"
IncludeDir["Glad"] = "Sorrow/vendor/Glad/include"
IncludeDir["ImGui"] = "Sorrow/vendor/imgui"
IncludeDir["glm"] = "Sorrow/vendor/glm"


group "Dependencies"
    include "Sorrow/vendor/GLFW"
    include "Sorrow/vendor/Glad"
    include "Sorrow/vendor/imgui"
group "" 

project "Sorrow"
	location "Sorrow"                  --��Ŀ�ļ������Ŀ¼����д�������Nut֮�µ�·�� "Sorrow/Sorrow"��
    kind "StaticLib"                --���ͣ���̬�⣩
    language "C++"                  --����
    cppdialect "C++17"              --C++��׼������ʱ��
    staticruntime "off"              --�Ƿ�����ʱ�⾲̬��������ʱ�⣨dll���Ե��ļ���Ҫ�رգ�

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "swpch.h"
	pchsource "Sorrow/src/swpch.cpp"
	
	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"

	}

	defines
    {
        "_CRT_SECURE_NO_WARNINGS",
        "GLFW_INCLUDE_NONE"
    }

	includedirs{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links {
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"
	

	defines{
	"SORROW_PLATFORM_WINDOWS",
	"SORROW_BUILD_DLL",
	"GLFW_INCLUDE_NONE"

	}

	postbuildcommands{
		("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
	}

	filter"configurations:Debug"
	    defines "SW_DEBUG"
		runtime "Debug"
		--buildoptions "/MDd"
	    symbols "On"

    filter"configurations:Release"
	    defines "SW_RELEASE"
		runtime "Release"
		--buildoptions "/MD"
	    optimize "On"

	filter"configurations:Dist"
	    defines "SW_DIST"
		runtime "Release"
		--buildoptions "/MD"
	    optimize "On"

project "Sandbox"
    location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
    staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"Sorrow/vendor/spdlog/include",
		"%{IncludeDir.glm}",
		"Sorrow/src",
		"Sorrow/vendor"
	}

	links{
		"Sorrow"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"
	

	    defines{
		 "SORROW_PLATFORM_WINDOWS"
	    }


	filter"configurations:Debug"
	    defines "SW_DEBUG"
		runtime "Debug"
		--buildoptions "/MDd"
	    symbols "On"

    filter"configurations:Release"
	    defines "SW_RELEASE"
		runtime "Release"
		--buildoptions "/MD"
	    optimize "On"

	filter"configurations:Dist"
	    defines "SW_DIST"
		runtime "Release"
		--buildoptions "/MD"
	    optimize "On"