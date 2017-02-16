@echo off
set name=%~n0
set build=..\build
if not defined RTM_VC_CONFIG set RTM_VC_CONFIG=Debug
set dlls=pc_type\%RTM_VC_CONFIG%\rtcpcl_pointcloud_type.dll
for %%d in (%dlls%) do (
  if not exist %%~nxd (
    if not exist %build%\%%d (
      echo %build%\%%d not found. Aborting...
      pause
      exit
    )
    copy %build%\%%d .
  )
)
start "%name%" "%build%\%name%\%RTM_VC_CONFIG%\%name%_standalone.exe"
