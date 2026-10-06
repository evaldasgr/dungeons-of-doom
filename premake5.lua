workspace "dungeons-of-doom"
   configurations { "Debug", "Release" }

project "dungeons-of-doom"
   kind "ConsoleApp"
   language "C++"
   files { "include/**.hpp", "src/**.cpp" }
   links { "raylib" }
   includedirs { "include" }
   targetdir "dist"

   filter { "configurations:Debug" }
      defines { "DEBUG" }
      symbols "On"
      targetsuffix "-d"

   filter { "configurations:Release" }
      defines { "NDEBUG" }
      optimize "On"
