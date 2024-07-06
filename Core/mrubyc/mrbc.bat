@echo off
rem
rem mruby/c compile script
rem

set MRBC=.\mrbc.exe


setlocal EnableDelayedExpansion
cd /d %~dp0

for %%r in (*.rb) do (
  type %%r >nul
  echo %MRBC% -B %%~nr %%r
  %MRBC% -B %%~nr %%r
  if errorlevel 1 exit /b 1
)
