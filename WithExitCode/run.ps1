clang -g main.c -o ./bin/main.exe && ./bin/main.exe

Write-Host
Write-Host "$([char]0x269E) LAST EXIT CODE : ( $LASTEXITCODE ) $([char]0x269F)"
Write-Host

# int max value
$intMax = [int]::MaxValue;
$intMin = [int]::MinValue;

switch ($LASTEXITCODE) {

    # 정수 최대값일때...
    $intMax { $result = '일요일'; Get-ChildItem -Path ./ }

    # 정수 최소값일때..
    $intMin { $result = '월요일'; Get-ChildItem -Path $env:TEMP }

    # -100 ~ -1
    { -100..-1 -contains $_ } { $result = '화요일'; Write-Host "Temp Folder: $env:TEMP" }

    # 0 ~ 100
    { 0..100 -contains $_ } {
        $result = '수요일';
    }

    # Single Return value
    1234 { $result = '목요일' }
    5678 { $result = '금요일' }
    2000 { $result = '토요일' }

    # ETC Value
    default { 
        $result = 'Unknown'; 
        $temp = $env:Path -replace ';', [System.Environment]::NewLine; 
        Write-Host $temp
        Clear-Host
        Write-Host "Welcome Black Back Room!!$([System.Environment]::NewLine)$([char]0x2603) Run...$([char]0x26F9)"
        & ".\run.ps1"
    }
}

$result

<# 
# $temp = $env:Path -replace ';', [System.Environment]::NewLine
#  bm on  C:/Temp/C
# ✤ ⭄ echo $temp

# {$intMin..$($intMin + 10000) -contains $_} { $result = '화요일' }
# {$($intMin + 10001)..$($intMin + 20000) -contains $_} { $result = '수요일' }
# {$($intMin + 20001)..-1 -contains $_} { $result = '목요일' }
# {$($intMax - 20000)..$($intMax - 10001) -contains $_} { $result = '금요일' }
# {$($intMax - 10000)..$intMax -contains $_} { $result = '토요일' }
Write-Host $intMin " ~" $intMax
Write-Host $intStep

if ($LASTEXITCODE -eq 0) {
    Write-Output "잘 마무리 되었습니다."
}

if ($LASTEXITCODE -eq $intMax) {
    Write-Host
    Write-Output "현재 폴더의 파일 목록입니다."
    Get-Childitem ./
}

if ($LASTEXITCODE -eq 2) {

    # (1) 파일탐색기를 열고 -> temp 폴더로 이동하라.
    # ii -Path $env:TEMP 
    # (2) temp folder 파일 모두 삭제하기.
    # Remove-Item -Path $env:TEMP\* -Recurse -Force -ErrorAction SilentlyContinue
}

# $day = (get-date).DayOfWeek.value__
# Write-Host $day (get-date).DayOfWeek
# ( get-date ).DayOfWeek | gm -f # gm is an alias for get-member



Add-Type @"
using System;
using System.Runtime.InteropServices;
public class SFW {
 [DllImport("user32.dll")]
 [return: MarshalAs(UnmanagedType.Bool)]
 public static extern bool SetForegroundWindow(IntPtr hWnd);
}
"@

$fw = (get-process explorer.exe).MainWindowHandle

[SFW]::SetForegroundWindow($fw)
#>