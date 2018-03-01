@ECHO OFF
PowerShell.exe -ExecutionPolicy Bypass -Command "'download-nuget.ps1'"

nuget restore -PackagesDirectory .\cinegy