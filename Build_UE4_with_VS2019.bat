@echo off
echo ============================================
echo UE4 使用 VS2019 编译脚本
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
echo 步骤1: 临时禁用VS2022的MSVC...
if exist "C:\Program Files\Microsoft Visual Studio\2022\Professional\VC\Tools\MSVC" (
    ren "C:\Program Files\Microsoft Visual Studio\2022\Professional\VC\Tools\MSVC" "MSVC_disabled"
    echo VS2022 MSVC已禁用
) else (
    echo VS2022 MSVC已经被禁用或不存在
)

echo.
echo 步骤2: 开始编译UE4...
cd /d "H:\Project\SP\LetsGoDevelop\ue4_tracking_rdcsp"

REM 使用VS2019编译
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional\MSBuild\Current\Bin\MSBuild.exe" UE4.sln /t:Build /p:Configuration="Development Editor" /p:Platform=Win64 /m

set BUILD_RESULT=%ERRORLEVEL%

echo.
echo 步骤3: 恢复VS2022的MSVC...
if exist "C:\Program Files\Microsoft Visual Studio\2022\Professional\VC\Tools\MSVC_disabled" (
    ren "C:\Program Files\Microsoft Visual Studio\2022\Professional\VC\Tools\MSVC_disabled" "MSVC"
    echo VS2022 MSVC已恢复
)

echo.
if %BUILD_RESULT% EQU 0 (
    echo ============================================
    echo 编译成功！
    echo ============================================
) else (
    echo ============================================
    echo 编译失败，错误代码: %BUILD_RESULT%
    echo ============================================
)

pause
exit /b %BUILD_RESULT%
