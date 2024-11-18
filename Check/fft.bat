REM AI生成AI生成AI生成AI生成AI生成AI生成AI生成
REM AI生成AI生成AI生成AI生成AI生成AI生成AI生成
REM AI生成AI生成AI生成AI生成AI生成AI生成AI生成
REM AI生成AI生成AI生成AI生成AI生成AI生成AI生成

@echo off
REM 编译两个程序
g++ xunlian2\B.cpp -o xunlian2\B.exe
IF ERRORLEVEL 1 (
    echo 编译失败，请检查代码。
    exit /b 1
)

g++ templetes\FFT-p.cpp -o templetes\FFT-p.exe
IF ERRORLEVEL 1 (
    echo 编译失败，请检查代码。
    exit /b 1
)

REM 生成测试用例
FOR /L %%i IN (1,1,100) DO (
    REM 生成两个随机的大整数
    FOR /F "usebackq tokens=*" %%A IN (`openssl rand -hex 50`) DO SET A=%%A
    SET A=%A:~0,20%
    FOR /F "usebackq tokens=*" %%B IN (`openssl rand -hex 50`) DO SET B=%%B
    SET B=%B:~0,20%

    REM 去除前导0
    FOR /F "tokens=* delims=0" %%a IN ("%A%") DO SET A=%%a
    IF "%A%"=="" SET A=0
    FOR /F "tokens=* delims=0" %%b IN ("%B%") DO SET B=%%b
    IF "%B%"=="" SET B=0

    REM 运行第一个程序
    echo %A% %B% | xunlian2\B.exe > output1.txt
    IF ERRORLEVEL 1 (
        echo 第一个程序运行失败。
        exit /b 1
    )

    REM 运行第二个程序
    SET n=0
    SET m=0
    SETLOCAL ENABLEDELAYEDEXPANSION
    SET "A_STR=%A%"
    SET "B_STR=%B%"
    SET /A n=0
    SET /A m=0
    :COUNT_A
    IF NOT "!A_STR:~%n%,1!"=="" (
        SET /A n+=1
        GOTO COUNT_A
    )
    :COUNT_B
    IF NOT "!B_STR:~%m%,1!"=="" (
        SET /A m+=1
        GOTO COUNT_B
    )
    ENDLOCAL & SET n=%n% & SET m=%m%

    echo %n% %m% > input_fft_p.txt
    SETLOCAL ENABLEDELAYEDEXPANSION
    SET "A_STR=%A%"
    SET "B_STR=%B%"
    FOR /L %%j IN (0,1,%n%-1) DO (
        SET /A index=%%j
        SET "digit=!A_STR:~%%j,1!"
        echo !digit!>> input_fft_p.txt
    )
    FOR /L %%j IN (0,1,%m%-1) DO (
        SET /A index=%%j
        SET "digit=!B_STR:~%%j,1!"
        echo !digit!>> input_fft_p.txt
    )
    ENDLOCAL

    templetes\FFT-p.exe < input_fft_p.txt > output2.txt
    IF ERRORLEVEL 1 (
        echo 第二个程序运行失败。
        exit /b 1
    )

    REM 比较输出
    FC output1.txt output2.txt >nul
    IF ERRORLEVEL 1 (
        echo 测试失败！输入：A=%A%, B=%B%
        echo 输出1：
        type output1.txt
        echo 输出2：
        type output2.txt
        exit /b 1
    ) ELSE (
        echo 测试 %%i 通过。
    )

    REM 清理临时文件
    del input_fft_p.txt
    del output1.txt
    del output2.txt
)

echo 所有测试均通过。