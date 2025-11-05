@echo off
echo ============================================
echo 修复VS2019注册表项
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
echo 添加32位注册表项...
reg add "HKEY_LOCAL_MACHINE\SOFTWARE\WOW6432Node\Microsoft\VisualStudio\SxS\VS7" /v 16.0 /t REG_SZ /d "C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional\" /f

echo.
echo 添加64位注册表项...
reg add "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\VisualStudio\SxS\VS7" /v 16.0 /t REG_SZ /d "C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional\" /f

echo.
echo ============================================
echo 验证注册表项...
echo ============================================

echo.
echo 32位注册表:
reg query "HKEY_LOCAL_MACHINE\SOFTWARE\WOW6432Node\Microsoft\VisualStudio\SxS\VS7" /v 16.0

echo.
echo 64位注册表:
reg query "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\VisualStudio\SxS\VS7" /v 16.0

echo.
echo ============================================
echo 修复完成！
echo ============================================
pause
