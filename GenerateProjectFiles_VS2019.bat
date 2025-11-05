@echo off
setlocal

:: 设置VS2019环境变量
set VS160COMNTOOLS=C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional\Common7\Tools\
set VSINSTALLDIR=C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional\
set VCToolsInstallDir=C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional\VC\Tools\MSVC\14.29.30133\

echo Setting up Unreal Engine 4 project files for VS2019...

:: 运行UBT生成项目文件
Engine\Binaries\DotNET\UnrealBuildTool.exe -projectfiles -project="%~dp0\YourProject.uproject" -game -rocket -progress -2019

if %ERRORLEVEL% NEQ 0 (
    echo ERROR: Failed to generate project files
    pause
    exit /b %ERRORLEVEL%
)

echo Project files generated successfully!
pause
