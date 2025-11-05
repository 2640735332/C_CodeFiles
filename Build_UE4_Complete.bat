@echo off
echo ============================================
echo UE4 完整编译脚本（自动处理VS2019/VS2022）
echo ============================================

REM 检查管理员权限
net session >nul 2>&1
if %errorLevel% neq 0 (
    echo 错误: 需要管理员权限！
    echo 请右键此文件，选择"以管理员身份运行"
    pause
    exit /b 1
)

echo.
echo [1/7] 检查VS2019是否存在...
if not exist "C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional\VC\Tools\MSVC\14.29.30133" (
    echo 错误: 找不到VS2019 MSVC 14.29.30133
    pause
    exit /b 1
)
echo OK - VS2019已安装

echo.
echo [2/7] 临时禁用VS2022的MSVC...
if exist "C:\Program Files\Microsoft Visual Studio\2022\Professional\VC\Tools\MSVC" (
    ren "C:\Program Files\Microsoft Visual Studio\2022\Professional\VC\Tools\MSVC" "MSVC_disabled"
    echo OK - VS2022 MSVC已禁用
) else if exist "C:\Program Files\Microsoft Visual Studio\2022\Professional\VC\Tools\MSVC_disabled" (
    echo OK - VS2022 MSVC已经被禁用
) else (
    echo OK - VS2022未安装或MSVC不存在
)

echo.
echo [3/7] 检查BuildConfiguration.xml...
if not exist "%APPDATA%\Unreal Engine\UnrealBuildTool\BuildConfiguration.xml" (
    echo 警告: BuildConfiguration.xml不存在，正在创建...
    mkdir "%APPDATA%\Unreal Engine\UnrealBuildTool" 2>nul
    
    echo ^<?xml version="1.0" encoding="utf-8" ?^> > "%APPDATA%\Unreal Engine\UnrealBuildTool\BuildConfiguration.xml"
    echo ^<Configuration xmlns="https://www.unrealengine.com/BuildConfiguration"^> >> "%APPDATA%\Unreal Engine\UnrealBuildTool\BuildConfiguration.xml"
    echo     ^<WindowsPlatform^> >> "%APPDATA%\Unreal Engine\UnrealBuildTool\BuildConfiguration.xml"
    echo         ^<Compiler^>VisualStudio2019^</Compiler^> >> "%APPDATA%\Unreal Engine\UnrealBuildTool\BuildConfiguration.xml"
    echo         ^<CompilerVersion^>14.29.30133^</CompilerVersion^> >> "%APPDATA%\Unreal Engine\UnrealBuildTool\BuildConfiguration.xml"
    echo         ^<VCToolChainDir^>C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional\VC\Tools\MSVC\14.29.30133^</VCToolChainDir^> >> "%APPDATA%\Unreal Engine\UnrealBuildTool\BuildConfiguration.xml"
    echo         ^<WindowsSdkVersion^>10.0.19041.0^</WindowsSdkVersion^> >> "%APPDATA%\Unreal Engine\UnrealBuildTool\BuildConfiguration.xml"
    echo         ^<bStrictConformanceMode^>false^</bStrictConformanceMode^> >> "%APPDATA%\Unreal Engine\UnrealBuildTool\BuildConfiguration.xml"
    echo         ^<AdditionalCompilerArguments^>/wd4756^</AdditionalCompilerArguments^> >> "%APPDATA%\Unreal Engine\UnrealBuildTool\BuildConfiguration.xml"
    echo     ^</WindowsPlatform^> >> "%APPDATA%\Unreal Engine\UnrealBuildTool\BuildConfiguration.xml"
    echo     ^<VCProjectFileGenerator^> >> "%APPDATA%\Unreal Engine\UnrealBuildTool\BuildConfiguration.xml"
    echo         ^<Version^>VisualStudio2019^</Version^> >> "%APPDATA%\Unreal Engine\UnrealBuildTool\BuildConfiguration.xml"
    echo     ^</VCProjectFileGenerator^> >> "%APPDATA%\Unreal Engine\UnrealBuildTool\BuildConfiguration.xml"
    echo     ^<BuildConfiguration^> >> "%APPDATA%\Unreal Engine\UnrealBuildTool\BuildConfiguration.xml"
    echo         ^<bAllowXGE^>false^</bAllowXGE^> >> "%APPDATA%\Unreal Engine\UnrealBuildTool\BuildConfiguration.xml"
    echo     ^</BuildConfiguration^> >> "%APPDATA%\Unreal Engine\UnrealBuildTool\BuildConfiguration.xml"
    echo ^</Configuration^> >> "%APPDATA%\Unreal Engine\UnrealBuildTool\BuildConfiguration.xml"
    
    echo OK - BuildConfiguration.xml已创建
) else (
    echo OK - BuildConfiguration.xml已存在
)

echo.
echo [4/7] 禁用NetcodeUnitTest插件...
cd /d H:\Project\SP\LetsGoDevelop\ue4_tracking_rdcsp\Engine\Plugins\NetcodeUnitTest\NetcodeUnitTest
if exist "NetcodeUnitTest.uplugin" (
    ren NetcodeUnitTest.uplugin NetcodeUnitTest.uplugin.disabled
    echo OK - 插件已禁用
) else (
    echo OK - 插件已经被禁用
)

echo.
echo [5/7] 清理中间文件...
cd /d H:\Project\SP\LetsGoDevelop\ue4_tracking_rdcsp
rmdir /s /q Engine\Intermediate 2>nul
rmdir /s /q .vs 2>nul
del /f /q UE4.sln 2>nul
echo OK - 清理完成

echo.
echo [6/7] 重新生成项目文件...
call GenerateProjectFiles.bat
if %ERRORLEVEL% NEQ 0 (
    echo 错误: GenerateProjectFiles失败
    goto :RESTORE_VS2022
)
echo OK - 项目文件已生成

echo.
echo [7/7] 开始编译...
echo 使用VS2019的MSBuild编译...
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional\MSBuild\Current\Bin\MSBuild.exe" UE4.sln /t:Build /p:Configuration="Development Editor" /p:Platform=Win64 /m /v:minimal

set BUILD_RESULT=%ERRORLEVEL%

:RESTORE_VS2022
echo.
echo [完成] 恢复VS2022的MSVC...
if exist "C:\Program Files\Microsoft Visual Studio\2022\Professional\VC\Tools\MSVC_disabled" (
    ren "C:\Program Files\Microsoft Visual Studio\2022\Professional\VC\Tools\MSVC_disabled" "MSVC"
    echo OK - VS2022 MSVC已恢复
)

echo.
echo ============================================
if %BUILD_RESULT% EQU 0 (
    echo 编译成功！
    echo UE4编辑器位置: Engine\Binaries\Win64\UE4Editor.exe
) else (
    echo 编译失败，错误代码: %BUILD_RESULT%
    echo 请查看上面的错误信息
)
echo ============================================
pause
exit /b %BUILD_RESULT%
