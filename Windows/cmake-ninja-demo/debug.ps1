function debug {
    param(
        [string]$target = "CmakeNinjaDemo.exe"
    )

    # 빌드 디렉터리 지정
    $buildDir = "build"

    # 1️⃣ CMake 빌드 (Debug 모드)
    Write-Host "🔧 Building project in Debug mode..."
    cmake --build $buildDir --config Debug

    # 2️⃣ 실행파일 경로 확인
    $exePath = Join-Path $buildDir $target

    if (-Not (Test-Path $exePath)) {
        Write-Host "❌ 실행 파일을 찾을 수 없습니다: $exePath"
        return
    }

    # 3️⃣ LLDB로 디버깅 시작
    Write-Host "🐞 Starting LLDB debugger for: $exePath"
    & lldb $exePath
}

debug
