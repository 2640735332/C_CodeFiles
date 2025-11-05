@echo off
echo ============================================
echo UE4 编译环境配置脚本
echo ============================================

echo.
echo 步骤1: 检查已安装的Windows SDK...
echo.
dir "C:\Program Files (x86)\Windows Kits\10\Include\10.0.*" /b
echo.

echo 步骤2: 检查Windows SDK 10.0.19041.0是否完整...
if exist "C:\Program Files (x86)\Windows Kits\10\Include\10.0.19041.0\um\windows.h" (
    echo [OK] SDK 10.0.19041.0 已安装
) else (
    echo [ERROR] SDK 10.0.19041.0 未安装或不完整
    echo 请从 https://developer.microsoft.com/windows/downloads/windows-sdk/ 下载安装
    pause
    exit /b 1
)

echo.
echo 步骤3: 配置 BuildConfiguration.xml...
echo.

set CONFIG_DIR=%APPDATA%\Unreal Engine\UnrealBuildTool
if not exist "%CONFIG_DIR%" mkdir "%CONFIG_DIR%"

echo ^<?xml version="1.0" encoding="utf-8" ?^> > "%CONFIG_DIR%\BuildConfiguration.xml"
echo ^<Configuration xmlns="https://www.unrealengine.com/BuildConfiguration"^> >> "%CONFIG_DIR%\BuildConfiguration.xml"
echo     ^<WindowsPlatform^> >> "%CONFIG_DIR%\BuildConfiguration.xml"
echo         ^<Compiler^>VisualStudio2019^</Compiler^> >> "%CONFIG_DIR%\BuildConfiguration.xml"
echo         ^<CompilerVersion^>14.29.30133^</CompilerVersion^> >> "%CONFIG_DIR%\BuildConfiguration.xml"
echo         ^<VCToolChainDir^>C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional\VC\Tools\MSVC\14.29.30133^</VCToolChainDir^> >> "%CONFIG_DIR%\BuildConfiguration.xml"
echo         ^<WindowsSdkVersion^>10.0.19041.0^</WindowsSdkVersion^> >> "%CONFIG_DIR%\BuildConfiguration.xml"
echo         ^<bStrictConformanceMode^>false^</bStrictConformanceMode^> >> "%CONFIG_DIR%\BuildConfiguration.xml"
echo         ^<AdditionalCompilerArguments^>/wd4756^</AdditionalCompilerArguments^> >> "%CONFIG_DIR%\BuildConfiguration.xml"
echo     ^</WindowsPlatform^> >> "%CONFIG_DIR%\BuildConfiguration.xml"
echo     ^<VCProjectFileGenerator^> >> "%CONFIG_DIR%\BuildConfiguration.xml"
echo         ^<Version^>VisualStudio2019^</Version^> >> "%CONFIG_DIR%\BuildConfiguration.xml"
echo     ^</VCProjectFileGenerator^> >> "%CONFIG_DIR%\BuildConfiguration.xml"
echo     ^<BuildConfiguration^> >> "%CONFIG_DIR%\BuildConfiguration.xml"
echo         ^<bAllowXGE^>false^</bAllowXGE^> >> "%CONFIG_DIR%\BuildConfiguration.xml"
echo     ^</BuildConfiguration^> >> "%CONFIG_DIR%\BuildConfiguration.xml"
echo ^</Configuration^> >> "%CONFIG_DIR%\BuildConfiguration.xml"

echo [OK] BuildConfiguration.xml 已创建
echo 位置: %CONFIG_DIR%\BuildConfiguration.xml
echo.

echo 步骤4: 显示配置内容...
echo.
type "%CONFIG_DIR%\BuildConfiguration.xml"
echo.

echo ============================================
echo 配置完成！
echo ============================================
echo.
echo 下一步操作:
echo 1. 禁用NetcodeUnitTest插件 (避免C4756错误)
echo    cd H:\Project\SP\LetsGoDevelop\ue4_tracking_rdcsp\Engine\Plugins\NetcodeUnitTest\NetcodeUnitTest
echo    ren NetcodeUnitTest.uplugin NetcodeUnitTest.uplugin.disabled
echo.
echo 2. 清理中间文件
echo    cd H:\Project\SP\LetsGoDevelop\ue4_tracking_rdcsp
echo    rmdir /s /q Engine\Intermediate
echo.
echo 3. 重新生成项目文件
echo    GenerateProjectFiles.bat
echo.
echo 4. 用VS2019打开并编译
echo.
pause
