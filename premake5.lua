-- Plik konfiguracyjny Premake 5
-- Konfiguracja dla projektów wieloplatformowych (Windows, Linux, macOS)

-- 1. Definicja Workspace (przestrzeni roboczej)
workspace "Ray_Tracing_PWJC"
    -- Ustawienia globalne dla wszystkich projektów
    configurations { "Debug", "Release" }
    startproject "Ray_Tracing"
    platforms { "x64" }

    -- Ustawienia domyślne dla wszystkich platform
    architecture "x64"
    language "C++"
    cppdialect "C++17"
    buildoptions { "-Wall", "-Wextra" }
    
    -- Katalogi wyjściowe i obiektów
    targetdir "bin/%{cfg.platform}/%{cfg.buildcfg}"
    objdir "obj/%{cfg.platform}/%{cfg.buildcfg}"

    -- 2. Ustawienia dla konfiguracji Debug
    filter "configurations:Debug"
        defines "DEBUG"
        symbols "On"
        
    -- 3. Ustawienia dla konfiguracji Release
    filter "configurations:Release"
        defines "NDEBUG"
        optimize "On"
        
    -- 4. Ustawienia specyficzne dla systemów uniksopodobnych (Linux, macOS)
    -- Używamy tego bloku, aby np. wyłączyć specyficzne flagi Windows
    filter { "system:linux", "system:macosx" }
        -- Przykład: Można tu dodać flagi do linkera potrzebne tylko na Linuksie

    -- 5. Ustawienia specyficzne dla Windows
    filter "system:windows"
        -- Przykład: Można tu dodać biblioteki specyficzne dla Windows

    -- Resetuje filtry do stanu bazowego
    filter {}

-- 6. Definicja Projektu
project "Ray_Tracing"
    kind "ConsoleApp" -- Typ projektu: aplikacja konsolowa
    
    -- Pliki źródłowe
    files {
        "Src/main.cpp",
        "Src/Ray.cpp",
        "Src/Renderer.cpp",
        "Src/Scene.cpp",
        "Src/Sphere.cpp"
    }

    -- 7. Ustawienia dla kompilatorów GCC/Clang na Linuksie i macOS
    filter { "system:linux", "system:macosx", "kind:ConsoleApp" }
        -- Dodajemy bibliotekę libstdc++ statycznie, aby uniknąć problemów z wersjami (opcjonalne, ale zalecane dla prostych aplikacji)
        -- To będzie działać tylko z gmake2 lub innymi generatorami GCC/Clang
        -- linkoptions { "-static-libstdc++" }